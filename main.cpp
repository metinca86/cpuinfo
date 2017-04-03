#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QProcess>
#include <QDebug>

using StringPairList = QList<QPair<QString,QString>>;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QProcess process;
    process.start("cat /proc/cpuinfo");
    process.waitForFinished(500);

    QString strAll{process.readAllStandardOutput()};
    strAll.remove("\t");

    // split the string into seperate sections
    // every section ends with double new line
    QStringList listAll{strAll.split("\n\n", QString::SkipEmptyParts)};

//    QHash<qint8, QStringList> hash;
//    hash.reserve(listAll.count());

//    // split the sectioned strings into every single line
//    for (int i = 0; i < listAll.count(); ++i) {
//        hash.insert(i, listAll.at(i).split("\n").);
//    }

    // Create a Hash which includes a List of Pairs
    // specifying Keys and Values of every single line
    QHash<qint8, StringPairList> hash;
    hash.reserve(listAll.count());

    // split the sectioned strings into every single line
    for (int i = 0; i < listAll.count(); ++i) {
        StringPairList list;

        for (const auto& str : listAll.at(i).split("\n"))
        {
            int pos = str.indexOf(":");
            // -2 because after the ':' there is a whitespace
            list.append(qMakePair<QString,QString>(str.left(pos), str.right(str.length() -2 -pos)));
        }

        hash.insert(i, list);
    }

    qDebug() << strAll;

//    qDebug() << list.filter("cpu MHz").join("\n") + QString("\n");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
