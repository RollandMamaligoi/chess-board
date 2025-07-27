#pragma once

#include <string>
#include <vector>
class Board;

class Piece {
protected:
	int posX, posY; //horizontal and vertical position;
	std::vector<std::pair<int, int>> possibleMoves; //a list of possible moves for a piece;
	std::string pieceColour;
public:
	Piece(int posX, int posY, std::string pieceColour);
	virtual std::vector<std::pair<int, int>> getPossibleMoves(Board& board, int posX, int posY) = 0; //a list of possible moves for a piece;
	virtual std::string getPieceType() = 0;
	std::string getPieceColour();
	virtual char getSymbol() = 0;
	std::pair<int, int> getPosition(int posX, int posY);
	virtual ~Piece() = default;
};