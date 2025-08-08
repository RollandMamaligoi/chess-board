#include "Pawn.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
std::vector<std::pair<int, int>> Pawn::getPossibleMoves(Board& board, int posX, int posY)
{

    std::vector<std::pair<int, int>> moves;
    if (pieceColour == "WHITE") {
        if (posX + 1 < 8 && posY + 1 < 8 && board.getPieceAt(posX + 1, posY + 1) != nullptr) {//if Pawn moves one square up and left/right, is within table boundaries 
            if (board.getPieceAt(posX + 1, posY + 1)->getPieceColour() != pieceColour) { //and that Piece is on the opposing team
                moves.push_back({ posX + 1, posY + 1 }); //Pawn can take
            }
        }
        if (posX - 1 >= 0 && posY + 1 < 8 && board.getPieceAt(posX - 1, posY + 1) != nullptr) {
            if (board.getPieceAt(posX - 1, posY + 1)->getPieceColour() != pieceColour) {
                moves.push_back({ posX - 1, posY + 1 });
            }
        }
        if (posX + 1 < 8 && board.getPieceAt(posX, posY + 1) == nullptr) {
            moves.push_back({ posX, posY + 1});
            if (firstMove && board.getPieceAt(posX, posY + 2) == nullptr)
                moves.push_back({ posX, posY + 2});
        }
        if (posY == 4) {
            std::string lastMove = board.lastMove("BLACK");
            int x = lastMove[1] - 'a';
            int y = lastMove[2] - '1';
            if (posX + 1 < 8) {
                if (x == posX + 1 && y == posY && lastMove[0] == 'P') {
                    moves.push_back({ posX + 1, posY + 1 });
                }
            }
            if (posX - 1 >= 0) {
                if (x == posX - 1 && y == posY && lastMove[0] == 'P') {
                    moves.push_back({ posX - 1, posY + 1 });
                }
            }
        }

    }
    else {
        if (posX - 1 >= 0 && posY - 1 >= 0 && board.getPieceAt(posX - 1, posY - 1) != nullptr) {
            if (board.getPieceAt(posX - 1, posY - 1)->getPieceColour() != pieceColour) {
                moves.push_back({ posX - 1, posY - 1 });
            }
        }
        if (posX + 1 < 8 && posY - 1 >= 0 && board.getPieceAt(posX + 1, posY - 1) != nullptr) {
            if (board.getPieceAt(posX + 1, posY - 1)->getPieceColour() != pieceColour) {
                moves.push_back({ posX + 1, posY - 1 });
            }
        }
        if (posY - 1 >= 0 && board.getPieceAt(posX, posY - 1) == nullptr) {
            moves.push_back({ posX, posY - 1}); 
            if (firstMove && board.getPieceAt(posX, posY  - 2 ) == nullptr) {
                moves.push_back({ posX, posY - 2});
            }
        }
        if (posY == 3) {
            std::string lastMove = board.lastMove("WHITE");
            int x = lastMove[1] - 'a';
            int y = lastMove[2] - '1';
            if (posX + 1 < 8) {
                if (x == posX + 1 && y == posY && lastMove[0] == 'P') {
                    moves.push_back({ posX + 1, posY - 1 });
                }
            }
            if (posX - 1 >= 0) {
                if (x == posX - 1 && y == posY && lastMove[0] == 'P') {
                    moves.push_back({ posX - 1, posY - 1 });
                }
            }
        }
    }
    int i = 0;
    while (i < moves.size()) {
        //board.showBoard();
        if (board.simulateMove(this, moves[i].first, moves[i].second, pieceColour)) {
         
            moves.erase(moves.begin() + i);
       
        }
        else i++;
    }

    return moves;
}

std::string Pawn::getPieceType()
{
    return pieceType;
}


char Pawn::getSymbol()
{
    return symbol;
}

bool Pawn::isFirstMove()
{
    return firstMove;
}

