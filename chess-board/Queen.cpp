#include "Queen.h"
#include "Board.h"
#include "Player.h"

std::vector<std::pair<int, int>> Queen::getPossibleMoves(Board& board, int posX, int posY)
{
    std::vector<std::pair<int, int>> moves;
    std::vector<std::pair<int, int>> directions = { {0, 1}, {1, 1}, {1, 0}, {1, -1} , {0 ,-1}, {-1, -1} , { -1, 0} , {-1, 1} };

    for (auto dir : directions) {
        int x = posX + dir.first, y = posY + dir.second;
        while (x >= 0 && x < 8 && y >= 0 && y < 8 && board.getPieceAt(x, y) == nullptr) {
            moves.push_back({ x, y });
            x += dir.first; y += dir.second;
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

std::string Queen::getPieceType()
{
    return pieceType;
}

char Queen::getSymbol()
{
    return symbol;
}

bool Queen::isFirstMove()
{
    return false;
}
