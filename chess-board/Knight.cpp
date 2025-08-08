#include "Knight.h"
#include "Board.h"
#include "Player.h"


std::vector<std::pair<int, int>> Knight::getPossibleMoves(Board& board, int posX, int posY)
{
    std::vector<std::pair<int, int>> moves;
    std::vector<std::pair<int, int>> directions = { {1, 2}, {2 , 1} , {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2 } };

    for (auto dir : directions) {
        int x = posX + dir.first, y = posY + dir.second;
        if(x >= 0 && x < 8 && y >= 0 && y < 8 && board.getPieceAt(x, y) == nullptr) {
            moves.push_back({ x, y });
        }
        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            Piece* piece = board.getPieceAt(x, y);
            if (piece != nullptr && piece->getPieceColour() != pieceColour) {
                moves.push_back({ x, y });
            }
        }
    }
    int i = 0;
    while (i < moves.size()) {
        if (board.simulateMove(this, moves[i].first, moves[i].second, pieceColour)) {
            moves.erase(moves.begin() + i);
        }
        else i++;
    }
    return moves;
}

std::string Knight::getPieceType()
{
    return pieceType;
}

char Knight::getSymbol()
{
    return symbol;
}

bool Knight::isFirstMove()
{
    return false;
}
