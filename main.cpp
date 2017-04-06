#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QSortFilterProxyModel>
#include <QQmlContext>

#include "cpuinfomodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/cpuinfo.ico"));

    // Create an instance of our ViewModel; this holds the total list of data
    auto cpuInfoModel = new CpuInfoModel();
    auto proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel( cpuInfoModel );
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("cpuInfoModel", cpuInfoModel );
    engine.rootContext()->setContextProperty("proxyModel", proxyModel );
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
