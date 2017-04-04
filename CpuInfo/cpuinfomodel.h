#ifndef CPUINFOMODEL_H
#define CPUINFOMODEL_H

#include <QStringListModel>

class CpuInfoModel : public QStringListModel
{
    Q_OBJECT

public:
    explicit CpuInfoModel(QObject *parent = 0);

//    Q_PROPERTY (QStringList processeorsData READ getProcessorsList)
//    Q_PROPERTY (int currentIndex MEMBER m_currentIndex WRITE setCBIndex)

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE void setCBIndex(int currentIndex);
    Q_INVOKABLE QStringList getProcessorsList() const;

private:
    QHash<qint8, QStringList> m_hashData;
    int m_currentIndex;
    QStringList m_processeorsData;
};

#endif // CPUINFOMODEL_H
