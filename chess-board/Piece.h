#pragma once

#include <string>
#include <vector>
class Board;
class Player;

class Piece {
protected:
	int posX, posY; //horizontal and vertical position;
	std::string pieceColour;
public:
	Piece(int posX, int posY, std::string pieceColour);
	virtual std::vector<std::pair<int, int>> getPossibleMoves(Board& board, int posX, int posY) = 0; //a list of possible moves for a piece;
	virtual std::string getPieceType() = 0;
	std::string getPieceColour();
	virtual char getSymbol() = 0;
	std::pair<int, int> getPosition();
	virtual ~Piece() = default;
	void setPosition(int X, int Y);
	virtual bool isFirstMove() = 0;
	virtual void setFirstMove(bool moved) = 0;
	virtual Piece* copy() = 0;
};