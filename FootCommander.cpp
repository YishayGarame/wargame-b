#include <string>
#include <vector>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;
#include "FootCommander.hpp"

FootCommander::FootCommander(){};
FootCommander::FootCommander(uint i)
{
    health = 150;
    damage = 20;
    player_number = i;
    type = "FootCommander";
}
int FootCommander::get_maxHealth()
{
    return max_health;
}
void FootCommander::action(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> loaction)
{
    double mindis = 1000000;
    double tempdis;
    int tarX = -1;
    int tarY = -1;
    std::pair<int, int> locationSoldier;

    //soldier loctaion
    int xLoc = loaction.first;
    int yLoc = loaction.second;

    //check the distance
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != nullptr)
            {
                if (board[i][j]->player_number != board[xLoc][yLoc]->player_number)
                {
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
    }
    //we have the mindis and the target location

    if (tarX != -1 && tarY != -1)
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

    //activate its own soldiers
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != nullptr)
            {
                if (board[i][j]->type == "FootSoldier" && board[i][j]->player_number == this->player_number)
                {
                    //Soldier *s = board[i][j];

                    locationSoldier.first = i;
                    locationSoldier.second = j;

                    board[i][j]->action(board, locationSoldier);
                }
            }
        }
    }
}

double FootCommander::checkDistance(int xLoc, int yLoc, int i, int j)
{
    double ans = sqrt((xLoc - i) * (xLoc - i) + (yLoc - j) * (yLoc - j));
    return ans;
}
