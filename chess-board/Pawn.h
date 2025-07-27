#pragma once
#include "Piece.h"

class Board;

class Pawn : public Piece{
protected:
	std::string pieceType = "PAWN";
	char symbol = 'P';
	bool firstMove = true; //on the first move the pawn can move 2 spaces
public:
	Pawn(int posX, int posY, std::string pieceColour) : Piece(posX, posY, pieceColour) {};
	std::vector<std::pair<int, int>> getPossibleMoves(Board& board, int posX, int posY);
	std::string getPieceType();
	void showMoves();
	char getSymbol();
};