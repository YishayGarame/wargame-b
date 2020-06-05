#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
#include "ParamedicCommander.hpp"

int ParamedicCommander::get_maxHealth()
{
    return max_health;
}
ParamedicCommander::ParamedicCommander(){};
ParamedicCommander::ParamedicCommander(uint i)
{
    health = 200;
    damage = 0;
    player_number = i;
    type = "ParamedicCommander";
}
void ParamedicCommander::action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction)
{
    std::pair<int, int> locationSoldier;

    //soldier loctaion
    int xLoc = loaction.first;
    int yLoc = loaction.second;

    //paramdicCommander action
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            //check if the same team
            if (board[i][j] != nullptr)
            {
                if (board[i][j]->player_number == board[xLoc][yLoc]->player_number)
                {
                    //check if its around the paramedic location
                    if (((i == xLoc - 1 && j == yLoc) || (i == xLoc + 1) ||
                         (j == yLoc - 1 && i == xLoc) || (j == yLoc + 1 && i == xLoc)))
                    {
                        board[i][j]->health = board[i][j]->get_maxHealth();
                    }
                    //if its diagnosed to its loctaion
                    if ((i == xLoc - 1 && j == yLoc - 1) || (i == xLoc + 1 && j == yLoc + 1) ||
                        ((i == xLoc - 1 && j == yLoc + 1) || (i == xLoc + 1 && j == yLoc - 1)))
                    {
                        board[i][j]->health = this->max_health;
                    }
                }
            }
        }
    }

    //activets its own paramedic soldiers
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != nullptr)
            {
                if (board[i][j]->type == "Paramedic" && this->player_number == board[i][j]->player_number)
                {
                    locationSoldier.first = i;
                    locationSoldier.second = j;
                    board[i][j]->action(board, locationSoldier);
                }
            }
        }
    }
}
