#pragma once
#include "Piece.h"

class Board;
class Player;

class Queen : public Piece {
private:
	std::string pieceType = "QUEEN";
	char symbol = 'Q';
public:
	Queen(int posX, int posY, std::string pieceColour) : Piece(posX, posY, pieceColour) {}
	std::vector<std::pair<int, int>> getPossibleMoves(Board& board, int posX, int posY);
	virtual std::string getPieceType();
	char getSymbol();
	bool isFirstMove();
	void setFirstMove(bool moved) {};
	Piece* copy() { return new Queen(*this); }
};