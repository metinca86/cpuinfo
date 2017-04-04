import QtQuick 2.6
import QtQuick.Controls 1.4
import Backend 1.0

Rectangle {
    id: rectangle

    width: 640
    height: 480
    antialiasing: true

    property alias cbProcessors: cbProcessors
    property alias cpuInfoModel: cpuInfoModel

    CpuInfoModel {
        id: cpuInfoModel
    }

    ComboBox {
        id: cbProcessors
        anchors.left: parent.left
        anchors.leftMargin: 258
        anchors.right: parent.right
        anchors.rightMargin: 258
        activeFocusOnPress: true
        anchors.top: parent.top
        anchors.topMargin: 15
    }

    ListView {
        id: listView
        x: 0
        y: 46
        width: 640
        height: 434
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.top: cbProcessors.bottom
        anchors.topMargin: 6
        anchors.left: parent.left
        model: cpuInfoModel
        delegate: Text {text: display}
    }
}
