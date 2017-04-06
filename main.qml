import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Window {
    visible: true
    x: 100
    y: 100
    width: 640
    height: 680
    title: qsTr("CPU Info")
//    minimumWidth: 640
    minimumHeight: 480

    MainForm {
        anchors.fill: parent

        cbProcessors.model: cpuInfoModel.getProcessorsList()
        cbProcessors.onCurrentIndexChanged: cpuInfoModel.setCBIndex(cbProcessors.currentIndex)
        tfSearch.onTextChanged: proxyModel.setFilterWildcard(tfSearch.text)

        Component {
            id: myDelegate

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                height: 25
                color: "lightgrey"
                border.color: "black"
                width: parent.width

                // displayed text in listview
                // elideRight text if it is too long
                Text {
                    id: displayText
                    text: display
                    width: parent.width
                    elide: Text.ElideRight
                    anchors.centerIn: parent
                    horizontalAlignment:Text.AlignHCenter
                    visible: true
                }

                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                    hoverEnabled: true
                }

                // whenever the mouseArea gets hovered
                // it shall make the popup visible or not
                Connections {
                    target: mouseArea
                    // makes the popup visible if the listview text is truncated/elided
                    onEntered: {popup.visible = displayText.truncated}
                    onExited: {popup.visible=false}
                }

                // a Popup which is used as a tooltip
                // it displays a lsitview item if it is too long
                Popup {
                    id: popup

                    contentWidth: popUpText.width
                    contentHeight: popUpText.height

                    x: mouseArea.mouseX +10
                    y: mouseArea.mouseY +10

                    Text {
                        id: popUpText
                        text: display
                        width: 150
                        maximumLineCount: 20
                        wrapMode: Text.WordWrap
                    }
                }
            }
        }
    }
}
