#pragma once
#include "Piece.h"

class Board;

class King : public Piece {
private:
	std::string pieceType = "KING";
	char symbol = 'K';
public:
	King(int posX, int posY, std::string pieceColour) :Piece(posX, posY, pieceColour) {};
	std::vector<std::pair<int, int>> getPossibleMoves(Board& board, int posX, int posY);
	std::string getPieceType();
	char getSymbol();
};