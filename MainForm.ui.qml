import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

Rectangle {
    id: rectangle

    width: 640
    height: 480
    antialiasing: true

    property alias listView: listView
    property alias cbProcessors: cbProcessors
    property alias tfSearch: tfSearch

    ListView {
        id: listView
        x: 0
        width: 640
        preferredHighlightEnd: 0
        highlightResizeDuration: 0
        highlightMoveDuration: 0
        highlightRangeMode: ListView.NoHighlightRange
        clip: false
        anchors.top: parent.top
        anchors.topMargin: 38
        anchors.bottomMargin: 8
        anchors.rightMargin: 8
        anchors.leftMargin: 12
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        model: proxyModel
        delegate: myDelegate
    }

    RowLayout {
        y: 8
        height: 25
        anchors.left: parent.left
        anchors.leftMargin: 12
        anchors.right: parent.right
        anchors.rightMargin: 8

        ComboBox {
            id: cbProcessors
            Layout.minimumWidth: 125
            Layout.fillWidth: false
            activeFocusOnPress: true
        }

        TextField {
            id: tfSearch
            Layout.fillWidth: true
            Layout.preferredHeight: 23
            placeholderText: qsTr("Search")
        }
    }
}
