import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    x: 100
    y: 100
    width: 640
    height: 480
    title: qsTr("CPU Info")
    minimumWidth: 640
    minimumHeight: 480

    MainForm {
        anchors.fill: parent

        cbProcessors.model: cpuInfoModel.getProcessorsList()
        cbProcessors.onCurrentIndexChanged: cpuInfoModel.setCBIndex(cbProcessors.currentIndex)
    }
}
