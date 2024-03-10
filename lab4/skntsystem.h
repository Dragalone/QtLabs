#ifndef SKNTSYSTEM_H
#define SKNTSYSTEM_H


class SkntSystem
{
public:
    SkntSystem(int process_time, int ee_weapons, int ew_weapons, int ea_weapons);
    int getProcess_time() const;
    void setProcess_time(int newProcess_time);

    int getEe_weapons() const;
    void setEe_weapons(int newEe_weapons);
    int getEw_weapons() const;
    void setEw_weapons(int newEw_weapons);
    int getEa_weapons() const;
    void setEa_weapons(int newEa_weapons);

    int getAvailable_ee_weapons() const;
    void setAvailable_ee_weapons(int newAvailable_ee_weapons);
    int getAvailable_ew_weapons() const;
    void setAvailable_ew_weapons(int newAvailable_ew_weapons);
    int getAvailable_ea_weapons() const;
    void setAvailable_ea_weapons(int newAvailable_ea_weapons);

private:
    int process_time;
    int ee_weapons;
    int ew_weapons;
    int ea_weapons;

    int available_ee_weapons;
    int available_ew_weapons;
    int available_ea_weapons;
};

#endif // SKNTSYSTEM_H
