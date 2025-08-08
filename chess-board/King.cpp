#include "King.h"
#include "Board.h"
#include "Player.h"


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
    if (firstMove && !board.isSquareAttacked(posX, posY, pieceColour)) {
        Piece* kingSideRook = board.getPieceAt(posX + 3, posY);
        if (kingSideRook != nullptr && kingSideRook->isFirstMove()) {
            if (board.getPieceAt(posX + 1, posY) == nullptr && board.getPieceAt(posX + 2, posY) == nullptr) {
                if (!board.isSquareAttacked(posX + 1, posY, pieceColour) && !board.isSquareAttacked(posX + 2, posY, pieceColour)) {
                    moves.push_back({ posX + 2, posY });
                }
            }
        }
        Piece* queenSideRook = board.getPieceAt(posX - 4, posY);
        if (queenSideRook != nullptr && queenSideRook->isFirstMove()) {
            if (board.getPieceAt(posX - 1, posY) == nullptr && board.getPieceAt(posX - 2, posY) == nullptr && board.getPieceAt(posX - 3, posY) == nullptr) {
                if (!board.isSquareAttacked(posX - 1, posY, pieceColour) && !board.isSquareAttacked(posX - 1, posY, pieceColour)) {
                    moves.push_back({ posX - 2, posY });
                }
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

std::string King::getPieceType()
{
    return pieceType;
}

char King::getSymbol()
{
    return symbol;
}

bool King::isFirstMove()
{
    return firstMove;
}
