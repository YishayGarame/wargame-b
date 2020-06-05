#include <string>
#include <vector>
#include <stdexcept>
#pragma once

using namespace std;
class Soldier
{

public:
    uint health;
    uint damage;
    uint player_number;
    string type;
    Soldier(){};
    virtual void action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction) = 0;
    virtual int get_maxHealth() = 0;
    virtual ~Soldier(){};
};