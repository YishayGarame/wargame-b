#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
#pragma once
#include "Soldier.hpp"

class Sniper : public Soldier
{
public:
    static const uint max_health = 100;
    Sniper();
    Sniper(uint player_number);
    virtual int get_maxHealth();
    ~Sniper(){};
    void action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction);
};
