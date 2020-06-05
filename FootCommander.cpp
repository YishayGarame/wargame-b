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
    int mindis = INT_MAX;
    int tempdis;
    int tarX;
    int tarY;
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
    board[tarX][tarY]->health -= this->damage;
    if (board[tarX][tarY]->health <= 0)
    {
        board[tarX][tarY] = nullptr;
        //delete soldier
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

int checkDistance(int xLoc, int yLoc, int i, int j)
{
    int ans = abs(xLoc - i) + abs(yLoc - j);
    return ans;
}
