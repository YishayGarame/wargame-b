#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
#include "Soldier.hpp"
#pragma once

class FootSoldier : public Soldier
{
public:
    static const uint max_health = 100;
    FootSoldier();
    FootSoldier(uint player_number);
    ~FootSoldier(){};
    virtual void action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction);
    int checkDistance(int xLoc, int yLoc, int i, int j);
};
