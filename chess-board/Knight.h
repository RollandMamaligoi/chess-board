#pragma once
#include "Piece.h"

class Board;
class Player;

class Knight : public Piece {
private:
	PieceType pieceType;
	char symbol = 'N';
public:
	Knight(int posX, int posY, Colour pieceColour) : Piece(posX, posY, pieceColour), pieceType(PieceType::KNIGHT) {};
	std::vector<std::pair<int, int>> getPossibleMoves(const Board& board, int posX, int posY);
	PieceType getPieceType();
	char getSymbol();
	bool isFirstMove();
	void setFirstMove(bool moved) {};
	Piece* copy();
};