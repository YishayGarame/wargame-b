#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
#pragma once
#include "Soldier.hpp"

class FootSoldier : public Soldier
{
public:
    static const uint max_health = 100;
    FootSoldier();
    FootSoldier(uint player_number);
    ~FootSoldier(){};
    virtual int get_maxHealth();
    virtual void action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction);
    virtual double checkDistance(int xLoc, int yLoc, int i, int j);
};
