#include "skntsystem.h"


SkntSystem::SkntSystem(int process_time, int ee_weapons, int ew_weapons, int ea_weapons) : process_time(process_time),
    ee_weapons(ee_weapons),
    ew_weapons(ew_weapons),
    ea_weapons(ea_weapons),
    available_ee_weapons(ee_weapons),
    available_ew_weapons(ew_weapons),
    available_ea_weapons(ea_weapons)
{}

int SkntSystem::getProcess_time() const
{
    return process_time;
}

void SkntSystem::setProcess_time(int newProcess_time)
{
    process_time = newProcess_time;
}

int SkntSystem::getEe_weapons() const
{
    return ee_weapons;
}

void SkntSystem::setEe_weapons(int newEe_weapons)
{
    ee_weapons = newEe_weapons;
}

int SkntSystem::getEw_weapons() const
{
    return ew_weapons;
}

void SkntSystem::setEw_weapons(int newEw_weapons)
{
    ew_weapons = newEw_weapons;
}

int SkntSystem::getEa_weapons() const
{
    return ea_weapons;
}

void SkntSystem::setEa_weapons(int newEa_weapons)
{
    ea_weapons = newEa_weapons;
}

int SkntSystem::getAvailable_ee_weapons() const
{
    return available_ee_weapons;
}

void SkntSystem::setAvailable_ee_weapons(int newAvailable_ee_weapons)
{
    available_ee_weapons = newAvailable_ee_weapons;
}

int SkntSystem::getAvailable_ew_weapons() const
{
    return available_ew_weapons;
}

void SkntSystem::setAvailable_ew_weapons(int newAvailable_ew_weapons)
{
    available_ew_weapons = newAvailable_ew_weapons;
}

int SkntSystem::getAvailable_ea_weapons() const
{
    return available_ea_weapons;
}

void SkntSystem::setAvailable_ea_weapons(int newAvailable_ea_weapons)
{
    available_ea_weapons = newAvailable_ea_weapons;
}


