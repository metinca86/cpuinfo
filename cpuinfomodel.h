#ifndef CPUINFOMODEL_H
#define CPUINFOMODEL_H

#include <QStringListModel>

class CpuInfoModel : public QStringListModel
{
    Q_OBJECT

public:
    explicit CpuInfoModel(QObject *parent = 0);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE void setCBIndex(int currentIndex);
    Q_INVOKABLE QStringList getProcessorsList() const;

private:
    QHash<int, QStringList> m_hashData;
    QStringList m_curDataList;
    QStringList m_processorsList;
};

#endif // CPUINFOMODEL_H
