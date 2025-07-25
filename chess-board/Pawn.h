#pragma once
#include "Piece.h"

class Board;

class Pawn : public Piece{
protected:
	std::string pieceType = "PAWN";
	char symbol = 'P';
public:
	Pawn(int posX, int posY, std::string pieceColour) : Piece(posX, posY, pieceColour) {};
	//std::vector<std::pair<int, int>> possibleMoves(Board& board, int posX, int posY);
	std::string getPieceType();
	char getSymbol();
};