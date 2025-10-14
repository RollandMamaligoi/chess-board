#include "Piece.h"
#include "Board.h"
#include "Player.h"
Piece::Piece(int posX, int posY, Colour pieceColour) {
    this->posX = posX;
    this->posY = posY;
    this->pieceColour = pieceColour;
}

Colour Piece::getPieceColour() const
{
    return pieceColour;
}

std::pair<int, int> Piece::getPosition()
{
    std::pair<int, int> position = std::make_pair(posX, posY);
    return position;
}

void Piece::setPosition(int X, int Y)
{
    posX = X; posY = Y;
}

