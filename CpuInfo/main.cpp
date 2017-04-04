#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "cpuinfomodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<CpuInfoModel>("Backend", 1, 0, "CpuInfoModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
