#ifndef SKNTOBJECT_H
#define SKNTOBJECT_H

#include <QString>



class SkntObject
{
public:
    SkntObject(int _speed, QString _type, QString _name, int _cannnons, int _damage);
    SkntObject(const SkntObject  &s);
    int getSpeed() const;
    void setSpeed(int newSpeed);
    const QString &getType() const;
    void setType(const QString &newType);
    const QString &getName() const;
    void setName(const QString &newName);
    int getCannons() const;
    void setCannons(int newCannons);
    int getDamage() const;
    void setDamage(int newDamage);

    int getZone() const;
    void setZone(int newZone);
    enum zone{
        Attack_zone = 0,
        Checked_zone = 1,
        Leaved_zone = 2
    };
private:
    int speed;
    QString type;
    QString name;
    int cannons;
    int damage;

    int zone;
};

#endif // SKNTOBJECT_H
