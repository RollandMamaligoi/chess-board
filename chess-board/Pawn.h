#pragma once
#include "Piece.h"
class Player;
class Board;
class Player;

class Pawn : public Piece{
protected:
	std::string pieceType = "PAWN";
	char symbol = 'P';
	bool firstMove = true; //on the first move the pawn can move 2 spaces
public:
	Pawn(int posX, int posY, std::string pieceColour) : Piece(posX, posY, pieceColour) {};
	std::vector<std::pair<int, int>> getPossibleMoves(Board& board, int posX, int posY);
	std::string getPieceType();
	char getSymbol();
	bool isFirstMove();
	void setFirstMove(bool moved) { firstMove = moved; };
	Piece* copy() { return new Pawn(*this); };
};