#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
#include "Soldier.hpp"

class SniperCommander : public Soldier
{
public:
    static const uint max_health = 120;
    SniperCommander();
    SniperCommander(uint player_number);
    int get_maxHealth();
    ~SniperCommander(){};
    void action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction);
};
