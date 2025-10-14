#pragma once
#include "Piece.h"

class Board;
class Player;

class King : public Piece {
private:
	PieceType pieceType;
	char symbol = 'K';
	bool firstMove = true;
public:
	King(int posX, int posY, Colour pieceColour) :Piece(posX, posY, pieceColour),pieceType(PieceType::KING) {};
	std::vector<std::pair<int, int>> getPossibleMoves(const Board& board, int posX, int posY);
	PieceType getPieceType();
	char getSymbol();
	bool isFirstMove();
	void setFirstMove(bool moved);
	Piece* copy();
};