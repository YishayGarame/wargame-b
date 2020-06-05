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
    int mindis = INT_MAX;
    int tempdis;
    int tarX;
    int tarY;

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

    //we have the mindis and the target location
    if (board[tarX][tarY] != nullptr)
    {
        board[tarX][tarY]->health = board[tarX][tarY]->health - this->damage;
        if (board[tarX][tarY]->health <= 0)
        {
            //  delete board[tarX][tarY];
            board[tarX][tarY] = nullptr;
        }
    }
}

int FootSoldier::checkDistance(int xLoc, int yLoc, int i, int j)
{
    int ans = abs(xLoc - i) + abs((yLoc - j));
    return ans;
}
