#include "Pawn.h"
#include "Board.h"
#include <iostream>
std::vector<std::pair<int, int>> Pawn::getPossibleMoves(Board& board, int posX, int posY)
{

    std::vector<std::pair<int, int>> moves;
    if (pieceColour == "WHITE") {
        if (posX + 1 < 8 && posY + 1 >= 0 && board.getPieceAt(posX + 1, posY + 1) != nullptr) {//if Pawn has a piece one square up and left/right of it and is within board boundaries
            if (board.getPieceAt(posX + 1, posY - 1)->getPieceColour() != pieceColour) { //and that Piece is on the opposing team
                moves.push_back({ posX - 1, posY + 1 }); //Pawn can take
            }
        }
        if (posX - 1 >= 0 && posY + 1 < 8 && board.getPieceAt(posX - 1, posY + 1) != nullptr) {
            if (board.getPieceAt(posX + 1, posY + 1)->getPieceColour() != pieceColour) {
                moves.push_back({ posX + 1, posY + 1 });
            }
        }
        if (firstMove && board.getPieceAt(posX, posY + 1) == nullptr) {
            moves.push_back({ posX , posY + 1 });
            if (board.getPieceAt(posX , posY + 2) == nullptr)
                moves.push_back({ posX, posY + 2});
        }


    }



    return moves;
}

std::string Pawn::getPieceType()
{
    return pieceType;
}

void Pawn::showMoves()
{
    char column = 'a';
    for (int i = 0; i < possibleMoves.size(); i++) {
        std::cout << (column + possibleMoves[i].first) << possibleMoves[i].second << " ";
    }
}

char Pawn::getSymbol()
{
    return symbol;
}
