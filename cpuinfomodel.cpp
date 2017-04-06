#include "cpuinfomodel.h"

#include <QProcess>
#include <QHash>
#include <QDebug>

CpuInfoModel::CpuInfoModel(QObject *parent)
    : QStringListModel(parent)
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

    // the data of processor is needed for a ComboBox which is selectable
    // so put it to a separate stringlist -> m_processorsList
    // all other data is relevant for the model and listview -> m_hashData
    m_hashData.reserve(listAll.count());
    QStringList tempList;
    for (int key = 0; key < listAll.count(); ++key) {
        tempList.clear();

        for (const auto& str : listAll.at(key).split("\n"))
        {
            if (str.contains("processor")){
                m_processorsList.append(str);
            }
            else {
                tempList.append(str);
            }
        }

        m_hashData.insert(key, tempList);
    }
}

int CpuInfoModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_curDataList.count();
}

QVariant CpuInfoModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)

    if (!index.isValid())
        return QVariant();

    if (index.row() > m_curDataList.count()-1)
        return QVariant();

    return m_curDataList.at(index.row());
}

void CpuInfoModel::setCBIndex(int currentIndex)
{
    if (m_hashData.contains(currentIndex))
    {
        m_curDataList = m_hashData.value(currentIndex);
        setStringList(m_curDataList);
    }
}

QStringList CpuInfoModel::getProcessorsList() const
{
    return m_processorsList;
}
