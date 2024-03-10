#include "skntobject.h"

SkntObject::SkntObject(int _speed, QString _type, QString _name, int _cannnons, int _damage)
{
    speed = _speed;
    type = _type;
    name = _name;
    cannons = _cannnons;
    damage = _damage;
    zone = SkntObject::Attack_zone;
}

SkntObject::SkntObject(const SkntObject &s)
{
    speed = s.speed;
    type = s.type;
    name = s.name;
    cannons = s.cannons;
    damage = s.damage;
}

int SkntObject::getSpeed() const
{
    return speed;
}

void SkntObject::setSpeed(int newSpeed)
{
    speed = newSpeed;
}

const QString &SkntObject::getType() const
{
    return type;
}

void SkntObject::setType(const QString &newType)
{
    type = newType;
}

const QString &SkntObject::getName() const
{
    return name;
}

void SkntObject::setName(const QString &newName)
{
    name = newName;
}

int SkntObject::getCannons() const
{
    return cannons;
}

void SkntObject::setCannons(int newCannons)
{
    cannons = newCannons;
}

int SkntObject::getDamage() const
{
    return damage;
}

void SkntObject::setDamage(int newDamage)
{
    damage = newDamage;
}

int SkntObject::getZone() const
{
    return zone;
}

void SkntObject::setZone(int newZone)
{
    zone = newZone;
}
