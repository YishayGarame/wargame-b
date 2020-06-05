#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
#include "SniperCommander.hpp"

int SniperCommander::get_maxHealth()
{
    return max_health;
}
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

    int maxHealth = 0;
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
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != nullptr)
            {
                if ((board[i][j]->player_number != board[xLoc][yLoc]->player_number))
                {
                    tempMaxHealth = board[i][j]->health;
                    if (tempMaxHealth > maxHealth)
                    {
                        maxHealth = tempMaxHealth;
                        tarX = i;
                        tarY = j;
                    }
                }
            }
        }
    }

    //we have the maxHelath and the target location
    if (board[tarX][tarY] != nullptr)
    {
        board[tarX][tarY]->health -= this->damage;
        if (board[tarX][tarY]->health <= 0)
        {
            board[tarX][tarY] = nullptr;
            // delete ~Soldier;
        }
    }

    //activate its own snipers soldiers
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != nullptr)
            {
                if (board[i][j]->type == "Sniper" && board[i][j]->player_number == this->player_number)
                {
                    locationSoldier.first = i;
                    locationSoldier.second = j;
                    board[i][j]->action(board, locationSoldier);
                }
            }
        }
    }
}
