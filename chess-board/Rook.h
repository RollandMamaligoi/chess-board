#pragma once
#include "Piece.h"

class Board;
class Player;

class Rook : public Piece {
private:
	std::string pieceType = "ROOK";
	char symbol = 'R';
	bool firstMove = true;
public:
	Rook(int posX, int posY, std::string pieceColour) : Piece(posX, posY, pieceColour) {};
	std::vector<std::pair<int, int>> getPossibleMoves(Board& board, int posX, int posY);
	std::string getPieceType();
	char getSymbol();
	bool isFirstMove();
	void setFirstMove(bool moved) { firstMove = moved; };
	Piece* copy() { return new Rook(*this); }
};