#ifndef COMMITEDMODEL_H
#define COMMITEDMODEL_H
#include <QAbstractListModel>
#include <QList>
#include <QVariant>
#include <QModelIndex>
#include "skntobject.h"
#include "skntsystem.h"

class CommitedModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CommitedModel(QObject *parent = 0);
    enum roles { // множество возможных значений поля
            InfoRole = Qt::DisplayRole,
            NameRole = Qt::UserRole+1, // заголовок для элемента модели ( для нас это имя объекта)
            SpeedRole = Qt::UserRole + 2,  // скорость
            TypeRole = Qt::UserRole + 3,  // тип
            CannonsRole = Qt::UserRole + 4,
            DamageRole = Qt::UserRole + 5
        };
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const; // функция доступа к данным
    void clear_data();
    int rowCount(const QModelIndex &parent) const; // количество элементов в модели
    virtual QHash<int, QByteArray> roleNames() const;
  //  virtual void sort(int column, Qt::SortOrder order);

public slots:
    void add_sknt_object(SkntObject sobj); // добавить объект
signals:
    void countChanged();
private:
    QList<SkntObject> sknt_objects; // список объектов
};
#endif // COMMITEDMODEL_H
