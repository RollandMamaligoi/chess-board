#pragma once
#include "Piece.h"

class Board;
class Player;

class Rook : public Piece {
private:
	PieceType pieceType;
	char symbol = 'R';
	bool firstMove = true;
public:
	Rook(int posX, int posY, Colour pieceColour) : Piece(posX, posY, pieceColour),pieceType(PieceType::ROOK) {};
	std::vector<std::pair<int, int>> getPossibleMoves(const Board& board, int posX, int posY);
	PieceType getPieceType();
	char getSymbol();
	bool isFirstMove();
	void setFirstMove(bool moved);
	Piece* copy();
};