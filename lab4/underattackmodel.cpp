#include "underattackmodel.h"
#include <QDebug>
//NameRole = Qt::DisplayRole, // заголовок для элемента модели ( для нас это имя объекта)
//SpeedRole = Qt::UserRole + 1,  // скорость
//TypeRole = Qt::UserRole + 2,  // тип
//CannonsRole = Qt::UserRole + 3,
//DamageRole = Qt::UserRole + 4
UnderAttackModel::UnderAttackModel(QObject *parent)
{
    system = new SkntSystem(1,1,1,1);
}

QVariant UnderAttackModel::data(const QModelIndex &index, int role) const
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

SkntObject* UnderAttackModel::get_object(const QModelIndex &index){
    if (index.row() < 0 || index.row() > sknt_objects.count()){
        return nullptr;
    }
    else {
        return &sknt_objects[index.row()];
    }
}

void UnderAttackModel::clear_data(){
    emit layoutAboutToBeChanged();
    sknt_objects.clear();
    emit layoutChanged();

}
int UnderAttackModel::rowCount(const QModelIndex &parent) const
{
    return sknt_objects.size();
}

QHash<int, QByteArray> UnderAttackModel::roleNames() const
{
    QHash<int, QByteArray> roles; // роли
    roles[NameRole] = "name";
    roles[SpeedRole] = "speed";
    roles[TypeRole] = "type";
    roles[CannonsRole] = "cannon";
    roles[DamageRole] = "damage";
    return roles;
}

bool comp1(SkntObject a, SkntObject b){
    return a.getSpeed() < b.getSpeed();
}

bool comp2(SkntObject a, SkntObject b){
    return a.getSpeed() > b.getSpeed();
}

void UnderAttackModel::sort(int column, Qt::SortOrder order)
{
        emit layoutAboutToBeChanged();
    if (order == Qt::AscendingOrder){
        std::sort(sknt_objects.begin(),sknt_objects.end(),comp1);
    } else {
        std::sort(sknt_objects.begin(),sknt_objects.end(),comp2);
    }
    emit layoutChanged();
}

SkntObject* UnderAttackModel::check()
{
    if (!sknt_objects.empty()){
        int ee_available = system->getEe_weapons();
        int ew_available = system->getEw_weapons();
        int ea_available = system->getEa_weapons();

        for (int i = 0; i < sknt_objects.size(); i++){
            int available;
            if (sknt_objects[i].getType() == "air") {
                available = ea_available;
            } else if  (sknt_objects[i].getType() == "water") {
                available = ew_available;
            } else {
                available = ee_available;
            }
            if (sknt_objects[i].getSpeed()-system->getProcess_time() <= 0 && sknt_objects[i].getCannons() <= available){
                emit layoutAboutToBeChanged();
                if (sknt_objects[i].getType() == "air") {
                    ea_available+=sknt_objects[i].getCannons();
                     system->setAvailable_ea_weapons(ea_available);
                } else if  (sknt_objects[i].getType() == "water") {
                    ew_available+=sknt_objects[i].getCannons();
                    system->setAvailable_ea_weapons(ew_available);
                } else {
                    ee_available+=sknt_objects[i].getCannons();
                    system->setAvailable_ea_weapons(ee_available);
                }
                SkntObject* obj= new SkntObject(sknt_objects[i]);
                sknt_objects.removeAt(i);
                obj->setZone(SkntObject::Checked_zone);
               emit layoutChanged();
                return obj;
            }else  if (sknt_objects[i].getSpeed()-system->getProcess_time() <= 0 && sknt_objects[i].getCannons() > available){
                emit layoutAboutToBeChanged();
                SkntObject* obj= new SkntObject(sknt_objects[i]);
                sknt_objects.removeAt(i);
                obj->setZone(SkntObject::Leaved_zone);
               emit layoutChanged();
                return obj;

            }  else if (sknt_objects[i].getSpeed()-system->getProcess_time() > 0 && sknt_objects[i].getCannons() <= available){
                sknt_objects[i].setSpeed(sknt_objects[i].getSpeed()-system->getProcess_time());
                if (sknt_objects[i].getType() == "air") {
                    ea_available-=sknt_objects[i].getCannons();
                     system->setAvailable_ea_weapons(ea_available);
                } else if  (sknt_objects[i].getType() == "water") {
                    ew_available-=sknt_objects[i].getCannons();
                    system->setAvailable_ea_weapons(ew_available);
                } else {
                    ee_available-=sknt_objects[i].getCannons();
                    system->setAvailable_ea_weapons(ee_available);
                }
            }else if (sknt_objects[i].getSpeed()-system->getProcess_time() > 0 && sknt_objects[i].getCannons() > available){
                sknt_objects[i].setSpeed(sknt_objects[i].getSpeed()-system->getProcess_time());
            }
        }


//    if (sknt_objects[0].getSpeed()-system->getProcess_time() <= 0){
//            emit layoutAboutToBeChanged();
//        SkntObject* obj= new SkntObject(sknt_objects[0]);
//        sknt_objects.removeFirst();
//            emit layoutChanged();
//        return obj;
//    } else {
//        sknt_objects[0].setSpeed(sknt_objects[0].getSpeed()-system->getProcess_time());
//    }
    }

    return nullptr;
}

void UnderAttackModel::add_sknt_object(SkntObject sobj)
{
    emit layoutAboutToBeChanged();
    sknt_objects << sobj;
    emit countChanged();
    emit layoutChanged();
}


