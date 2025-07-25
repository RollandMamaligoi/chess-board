#pragma once
#include "Piece.h"

class Board;

class Rook : public Piece {
private:
	std::string pieceType = "ROOK";
	char symbol = 'R';
public:
	Rook(int posX, int posY, std::string pieceColour) : Piece(posX, posY, pieceColour) {};
	//std::vector<std::pair<int, int>> possibleMoves(const Board& board, int posX, int posY);
	std::string getPieceType();
	char getSymbol();
};