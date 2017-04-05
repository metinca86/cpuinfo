#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>

#include "cpuinfomodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/cpuinfo.ico"));

    qmlRegisterType<CpuInfoModel>("Backend", 1, 0, "CpuInfoModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
