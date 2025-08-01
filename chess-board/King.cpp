#include "King.h"
#include "Board.h"




//std::vector<std::pair<int, int>> King::possibleMoves(Board& board, int posX, int posY)
//{
//    
//}

std::vector<std::pair<int, int>> King::getPossibleMoves(Board& board, int posX, int posY)
{
    std::vector<std::pair<int, int>> moves;
    std::vector<std::pair<int, int>> kingDir = { {0, 1} , {1,1},{1,0},{1, -1},{0, -1},{-1, -1},{-1, 0}, {-1, 1} };
    for (auto dir : kingDir) {
        int x = posX + dir.first, y = posY + dir.second;
        if (x >= 0 && x < 8 && y >= 0 && y < 8 && board.getPieceAt(x, y) == nullptr) {
            moves.push_back({ x, y });
        }
        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            Piece* piece = board.getPieceAt(x, y);
            if (piece != nullptr && piece->getPieceColour() != pieceColour) {
                moves.push_back({ x, y });
            }
        }
    }
    return moves;
}

std::string King::getPieceType()
{
    return pieceType;
}

char King::getSymbol()
{
    return symbol;
}
