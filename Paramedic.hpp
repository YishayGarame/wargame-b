#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
#pragma once
#include "Soldier.hpp"

class Paramedic : public Soldier
{
public:
    static const uint max_health = 100;
    Paramedic();
    Paramedic(uint player_number);
    virtual int get_maxHealth();
    ~Paramedic(){};
    virtual void action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction);
};
