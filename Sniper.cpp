#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Sniper.hpp"

Sniper::Sniper(){};
int Sniper::get_maxHealth()
{
    return max_health;
}

Sniper::Sniper(uint i)
{
    health = 100;
    damage = 50;
    player_number = i;
    type = "Sniper";
}
void Sniper::action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction)
{

    int maxHealth = -1;
    int tempMaxHealth;
    int tarX = -1;
    int tarY = -1;

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
    if (tarX != -1 && tarY != -1)
    {
        //we have the maxHelath and the target location
        if (board[tarX][tarY] != nullptr)
        {

            if (board[tarX][tarY]->health <= this->damage)
            {
                board[tarX][tarY] = nullptr;
            }
            else
            {
                board[tarX][tarY]->health = board[tarX][tarY]->health - this->damage;
             }
        }
    }
}
