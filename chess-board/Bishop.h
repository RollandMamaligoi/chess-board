#pragma once
#include "Piece.h"

class Board;

class Bishop : public Piece {
private:
	std::string pieceType = "BISHOP";
	char symbol = 'B';
public:
	Bishop(int posX, int posY, std::string pieceColour) : Piece(posX, posY, pieceColour) {};
	//std::vector<std::pair<int, int>> possibleMoves(Board& board, int posX, int posY);
	std::string getPieceType();
	char getSymbol();
};