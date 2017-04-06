import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    visible: true
    x: 100
    y: 100
    width: 640
    height: 680
    title: qsTr("CPU Info")
    minimumWidth: 640
    minimumHeight: 480

    MainForm {
        anchors.fill: parent

        cbProcessors.model: cpuInfoModel.getProcessorsList()
        cbProcessors.onCurrentIndexChanged: cpuInfoModel.setCBIndex(cbProcessors.currentIndex)
        tfSearch.onTextChanged: proxyModel.setFilterWildcard(tfSearch.text)


        // set a background color for listview items
        // elideRight text if it is too long
        // show a tooltip of hovered item
        Component {
                id: myDelegate
                Rectangle {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: 25
                    color: "lightgrey"
                    border.color: "black"
                    width: parent.width

                    Text {
                        id: displayText
                        text: display
                        width: parent.width
                        elide: Text.ElideRight
                        anchors.centerIn: parent
                        horizontalAlignment:Text.AlignHCenter
                    }

                    Text {
                        id: toolTipText
                        text: display
                        width: parent.width
                        wrapMode: Text.WordWrap
                        visible: false
                    }

                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        hoverEnabled: true
                    }

                    ToolTip {
                        id: toolTip
                        text: toolTipText.text

                        Connections {
                            target: mouseArea
                            onEntered: {toolTip.visible=true}
                            onExited: {toolTip.visible=false}
                        }

                    }
                }
        }
    }
}
