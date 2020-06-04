#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
#include "SniperCommander.hpp"

SniperCommander::SniperCommander(){};
SniperCommander::SniperCommander(uint i)
{
    health = 120;
    damage = 100;
    player_number = i;
    type = "SniperCommander";
}
void SniperCommander::action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction)
{

    int maxHelath = 0;
    int tempMaxHealth;
    int tarX;
    int tarY;
    std::pair<int, int> locationSoldier;

    //soldier loctaion
    int xLoc = loaction.first;
    int yLoc = loaction.second;

    //check the stronger soldier
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != nullptr && (board[i][j]->player_number != board[xLoc][yLoc]->player_number))
            {
                tempMaxHealth = board[i][j]->health;
                if (tempMaxHealth > maxHelath)
                {
                    maxHelath = tempMaxHealth;
                    tarX = i;
                    tarY = j;
                }
            }
        }
    }

    //we have the maxHelath and the target location
    board[tarX][tarY]->health -= this->damage;
    if (board[tarX][tarY]->health <= 0)
    {
        //i want to check if board.hassoldiers but do know how
        board[tarX][tarY] = nullptr;
        // delete ~Soldier;
    }

    //activate its own snipers soldiers
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            //board[i][j] != NULL &&
            if (board[i][j] != nullptr && board[i][j]->type == "Sniper" && board[i][j]->player_number == this->player_number)
            {
                locationSoldier.first = i;
                locationSoldier.second = j;
                board[i][j]->action(board, locationSoldier);
            }
        }
    }
}
