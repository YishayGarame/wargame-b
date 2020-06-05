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

    int maxHealth = 0;
    int tempMaxHealth;
    int tarX;
    int tarY;

    //soldier loctaion
    int xLoc = loaction.first;
    int yLoc = loaction.second;

    //check the stronger soldier
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[j].size(); j++)
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
        board[tarX][tarY]->health = board[tarX][tarY]->health - this->damage;
        // cout << board[tarX][tarY]->type << "has that point of health " << board[tarX][tarY]->health << endl;
        if (board[tarX][tarY]->health <= 0)
        {
            // delete board[tarX][tarY];
            board[tarX][tarY] = nullptr;
        }
    }
}
