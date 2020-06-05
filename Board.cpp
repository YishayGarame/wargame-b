#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"
#include <iostream>
using namespace WarGame;

Soldier *&Board::operator[](std::pair<int, int> location)
{
    return board[location.first][location.second];
}

Soldier *Board::operator[](std::pair<int, int> location) const
{
    return board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
{
    if (source.first >= board.size() || source.first < 0 || source.second >= board.size() || source.second < 0)
    {
        throw std::invalid_argument("Invalid source input");
    }
    if (board[source.first][source.second] == nullptr)
    {
        throw std::invalid_argument("Invalid source input");
    }
    if (board[source.first][source.second]->player_number != player_number)
    {
        throw std::invalid_argument("not the same team player");
    }

    int i = source.first;
    int j = source.second;
    int lengthI = board.size();
    int lengthJ = board[0].size();

    std::pair<int, int> location;
    switch (direction)
    {
    case (Up):

        if (((i + 1) >= lengthI) || (board[i + 1][j] != nullptr))
        {
            throw std::runtime_error("std::invalid_argument2 ");
        }
        else
        {

            location.first = i + 1;
            location.second = j;
            Soldier *temp = board[i][j];
            board[i + 1][j] = temp;
            board[i][j] = nullptr;
            temp->action(board, location);
        }
        break;

    case (Down):
        if (((i - 1) < 0) || board[i - 1][j] != nullptr)
        {
            throw runtime_error("std::invalid_argument3 ");
        }
        else
        {
            location.first = i - 1;
            location.second = j;
            Soldier *temp = board[i][j];
            board[i - 1][j] = temp;
            board[i][j] = nullptr;
            temp->action(board, location);
        }
        break;

    case (Left):
        if (((j - 1) < 0) || board[i][j - 1] != nullptr)
        {
            throw runtime_error("std::invalid_argument4 ");
        }
        else
        {
            location.first = i;
            location.second = j - 1;
            Soldier *temp = board[i][j];
            board[i][j - 1] = temp;
            board[i][j] = nullptr;
            temp->action(board, location);
        }
        break;

    case (Right):
        if (((j + 1) >= lengthJ) || board[i][j + 1] != nullptr)
        {
            throw runtime_error("std::invalid_argument 5");
        }
        else
        {
            location.first = i;
            location.second = j + 1;
            Soldier *temp = board[i][j];
            board[i][j + 1] = temp;
            board[i][j] = nullptr;
            temp->action(board, location);
        }
        break;
    }
}

bool Board::has_soldiers(uint player_number) const
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != nullptr)
            {
                if (board[i][j]->player_number == player_number)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
