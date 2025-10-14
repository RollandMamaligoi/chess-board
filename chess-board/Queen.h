#pragma once
#include "Piece.h"

class Board;
class Player;

class Queen : public Piece {
private:
	PieceType pieceType;
	char symbol = 'Q';
public:
	Queen(int posX, int posY, Colour pieceColour) : Piece(posX, posY, pieceColour),pieceType(PieceType::QUEEN) {}
	std::vector<std::pair<int, int>> getPossibleMoves(const Board& board, int posX, int posY);
	virtual PieceType getPieceType();
	char getSymbol();
	bool isFirstMove();
	void setFirstMove(bool moved) {};
	Piece* copy();
};