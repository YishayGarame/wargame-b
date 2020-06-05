#include <string>
#include <vector>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;
#include "FootSoldier.hpp"

//FootSoldier::FootSoldier() : Soldier::health(100), Soldier::damage(10), player_number(1), type("FootSoldier"){};
int FootSoldier::get_maxHealth()
{
    return max_health;
}
FootSoldier ::FootSoldier(){};
FootSoldier::FootSoldier(uint i)
{
    health = 100;
    damage = 10;
    player_number = i;
    type = "FootSoldier";
}
void FootSoldier::action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction)
{

    double mindis = 1000000;
    double tempdis;
    int tarX = -1;
    int tarY = -1;

    //soldier loctaion
    int xLoc = loaction.first;
    int yLoc = loaction.second;

    //check the distance
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != nullptr && board[xLoc][yLoc] != nullptr)
            {

                if ((board[i][j]->player_number != board[xLoc][yLoc]->player_number))
                {

                    tempdis = checkDistance(xLoc, yLoc, i, j);
                    if (tempdis < mindis)
                    {
                        tarX = i;
                        tarY = j;
                        mindis = tempdis;
                    }
                }
            }
        }
    }
    if (tarX != -1 && tarY != -1)
    {
        //we have the mindis and the target location
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

double FootSoldier::checkDistance(int xLoc, int yLoc, int i, int j)
{
    double ans = sqrt((xLoc - i) * (xLoc - i) + (yLoc - j) * (yLoc - j));
    return ans;
}
