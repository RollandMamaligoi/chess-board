#pragma once
#include "Piece.h"
class Player;
class Board;

class Bishop : public Piece {
private:
	PieceType pieceType;
	char symbol = 'B';
public:
	Bishop(int posX, int posY, Colour pieceColour) : Piece(posX, posY, pieceColour), pieceType(PieceType::BISHOP) {};
	std::vector<std::pair<int, int>> getPossibleMoves(const Board& board, int posX, int posY);
	PieceType getPieceType();
	char getSymbol();
	bool isFirstMove();
	void setFirstMove(bool moved) {};
	Piece* copy();
};