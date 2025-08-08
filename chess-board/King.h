#pragma once
#include "Piece.h"

class Board;
class Player;

class King : public Piece {
private:
	std::string pieceType = "KING";
	char symbol = 'K';
	bool firstMove = true;
public:
	King(int posX, int posY, std::string pieceColour) :Piece(posX, posY, pieceColour) {};
	std::vector<std::pair<int, int>> getPossibleMoves(Board& board, int posX, int posY);
	std::string getPieceType();
	char getSymbol();
	bool isFirstMove();
	void setFirstMove(bool moved) { firstMove = moved; };
	Piece* copy() { return new King(*this); }
};