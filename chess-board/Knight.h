#pragma once
#include "Piece.h"

class Board;

class Knight : public Piece {
private:
	std::string pieceType = "KNIGHT";
	char symbol = 'N';
public:
	Knight(int posX, int posY, std::string pieceColour) : Piece(posX, posY, pieceColour) {};
	//std::vector<std::pair<int, int>> possibleMoves(const Board& board, int posX, int posY);
	std::string getPieceType();
	char getSymbol();
};