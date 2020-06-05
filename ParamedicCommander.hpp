#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic
{
public:
    static const uint max_health = 200;
    ParamedicCommander();
    ParamedicCommander(uint player_number);
    int get_maxHealth();
    ~ParamedicCommander(){};
    void action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction);
};
