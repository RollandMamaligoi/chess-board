#pragma once

#include <string>
#include <vector>
#include "PieceType.h"
class Board;
class Player;


class Piece {
protected:
	int posX, posY; //horizontal and vertical position;
	Colour pieceColour;
public:
	Piece(int posX, int posY, Colour pieceColour);
	virtual ~Piece() = default;
	virtual std::vector<std::pair<int, int>> getPossibleMoves(const Board& board, int posX, int posY) = 0; //a list of possible moves for a piece;
	virtual PieceType getPieceType() = 0;
	Colour getPieceColour() const;
	virtual char getSymbol() = 0;
	std::pair<int, int> getPosition();
	void setPosition(int X, int Y);
	virtual bool isFirstMove() = 0;
	virtual void setFirstMove(bool moved) = 0;
	virtual Piece* copy() = 0;
};