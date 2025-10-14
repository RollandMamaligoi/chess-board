#pragma once
#include "Piece.h"
class Player;
class Board;

class Pawn : public Piece{
protected:
	PieceType pieceType;
	char symbol = 'P';
	bool firstMove = true; //on the first move the pawn can move 2 spaces
public:
	Pawn(int posX, int posY, Colour pieceColour) : Piece(posX, posY, pieceColour), pieceType(PieceType::PAWN) {};
	std::vector<std::pair<int, int>> getPossibleMoves(const Board& board, int posX, int posY);
	PieceType getPieceType();
	char getSymbol();
	bool isFirstMove();
	void setFirstMove(bool moved);
	Piece* copy();
};