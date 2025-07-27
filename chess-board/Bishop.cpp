#include "Bishop.h"
#include "Board.h"

//std::vector<std::pair<int, int>> Bishop::possibleMoves(Board& board, int posX, int posY)
//{
//    return ;
//}

std::vector<std::pair<int, int>> Bishop::getPossibleMoves(Board& board, int posX, int posY)
{
    std::vector<std::pair<int, int>> moves;
    return moves;
}

std::string Bishop::getPieceType()
{
    return pieceType;
}

char Bishop::getSymbol()
{
    return symbol;
}
