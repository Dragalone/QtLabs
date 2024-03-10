#include "commitedmodel.h"
#include <QDebug>
//NameRole = Qt::DisplayRole, // заголовок для элемента модели ( для нас это имя объекта)
//SpeedRole = Qt::UserRole + 1,  // скорость
//TypeRole = Qt::UserRole + 2,  // тип
//CannonsRole = Qt::UserRole + 3,
//DamageRole = Qt::UserRole + 4
CommitedModel::CommitedModel(QObject *parent)
{

}

QVariant CommitedModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > sknt_objects.count())
        return QVariant();
    const SkntObject & ob = sknt_objects[index.row()];
        if (role == NameRole)
            return ob.getName();
        else if (role == CannonsRole)
            return ob.getCannons();
        else if (role == DamageRole)
            return ob.getDamage();
        else if (role == SpeedRole)
            return ob.getSpeed();
        else if (role == TypeRole)
            return ob.getType();
        else if (role == InfoRole){
            QString s = "Имя: " + ob.getName() + "  Урон: " + QString::number(ob.getDamage());
            return s;
        }
        return QVariant();
}


void CommitedModel::clear_data(){
    emit layoutAboutToBeChanged();
    sknt_objects.clear();
    emit layoutChanged();
}

int CommitedModel::rowCount(const QModelIndex &parent) const
{
    return sknt_objects.size();
}

QHash<int, QByteArray> CommitedModel::roleNames() const
{
    QHash<int, QByteArray> roles; // роли
    roles[NameRole] = "name";
    roles[SpeedRole] = "speed";
    roles[TypeRole] = "type";
    roles[CannonsRole] = "cannon";
    roles[DamageRole] = "damage";
    return roles;
}
//bool comp1(SkntObject a, SkntObject b){
//    return a.getSpeed() < b.getSpeed();
//}
//bool comp2(SkntObject a, SkntObject b){
//    return a.getSpeed() > b.getSpeed();
//}
//void CommitedModel::sort(int column, Qt::SortOrder order)
//{
//        emit layoutAboutToBeChanged();
//    if (order == Qt::AscendingOrder){
//        std::sort(sknt_objects.begin(),sknt_objects.end(),comp1);
//    } else {
//        std::sort(sknt_objects.begin(),sknt_objects.end(),comp2);
//    }
//    emit layoutChanged();
//}


void CommitedModel::add_sknt_object(SkntObject sobj)
{
    emit layoutAboutToBeChanged();
    sknt_objects << sobj;
    emit countChanged();
    emit layoutChanged();
}


