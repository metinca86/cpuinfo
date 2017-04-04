#include "cpuinfomodel.h"

#include <QProcess>
#include <QHash>
#include <QDebug>

CpuInfoModel::CpuInfoModel(QObject *parent)
    : QStringListModel(parent)
    , m_hashData()
    , m_currentIndex(0)
    , m_processeorsData()
{
    // Read informations of /proc/cpuinfo
    QProcess process;
    process.start("cat /proc/cpuinfo");
    process.waitForFinished(500);
    QString strAll{process.readAllStandardOutput()};

    strAll.remove("\t");

    // split the string into seperate sections
    // every section ends with double new line
    QStringList listAll{strAll.split("\n\n", QString::SkipEmptyParts)};

    // Create a Hash which includes a List of Pairs
    // specifying Keys and Values of every single line
    m_hashData.reserve(listAll.count());

    // split the sectioned strings into every single line
    for (qint8 i = 0; i < listAll.count(); ++i) {
        QStringList list;

        for (const auto& str : listAll.at(i).split("\n"))
        {

            if (str.contains("processor")){
                m_processeorsData.append(str);
            }
            else {
                list.append(str);
            }
        }

        m_hashData.insert(i, list);
    }
}

int CpuInfoModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return stringList().count();
}

QVariant CpuInfoModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)

    if (!index.isValid())
        return QVariant();

    return stringList().at(index.row());
}

void CpuInfoModel::setCBIndex(int currentIndex)
{
    if (m_hashData.contains(currentIndex))
    {
        m_currentIndex = currentIndex;
        setStringList(m_hashData.value(currentIndex));
    }

}

QStringList CpuInfoModel::getProcessorsList() const
{
    return m_processeorsData;
}
