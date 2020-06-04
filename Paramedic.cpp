#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
#include "Paramedic.hpp"

Paramedic::Paramedic(){};
Paramedic::Paramedic(uint i)
{
    health = 100;
    damage = 0;
    player_number = i;
    type = "Paramedic";
}
void Paramedic::action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction)
{

    //soldier loctaion
    int xLoc = loaction.first;
    int yLoc = loaction.second;

    //check around paramedic location
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            //check if the same team
            if (board[i][j] != nullptr && board[i][j]->player_number == board[xLoc][yLoc]->player_number)
            {
                //check if its around the paramedic location
                if (((i == xLoc - 1 && j == yLoc) || (i == xLoc + 1) ||
                     (j == yLoc - 1 && i == xLoc) || (j == yLoc + 1 && i == xLoc)))
                {
                    board[i][j]->health = this->max_health;
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
