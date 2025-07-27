#include "Rook.h"
#include "Board.h"

//std::vector<std::pair<int, int>> Rook::possibleMoves(const Board& board, int posX, int posY)
//{
//    return ;
//}

std::vector<std::pair<int, int>> Rook::getPossibleMoves(Board& board, int posX, int posY)
{
    std::vector<std::pair<int, int>> moves;
    return moves;
}

std::string Rook::getPieceType()
{
    return pieceType;
}

char Rook::getSymbol()
{
    return symbol;
}
