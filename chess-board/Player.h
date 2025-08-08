#pragma once
#include <vector>
#include <string>

class Piece;
class Board;

class Player {
protected:
	std::vector<Piece*> Pieces;
	std::string colour;
	bool check = false;
public:
	Player(Board& board, std::string colour);
	std::string getColour();
	std::vector<Piece*> getPieces();
	void printPieces();
	void setCheckStatus();
	bool isInCheck();
	void deletePiece(Piece* piece);
};