#pragma once
#include <vector>
#include <string>

class Piece;
class Board;
enum class Colour;



class Player {
protected:
	std::vector<Piece*> Pieces;
	Colour colour;
	bool check = false;
public:
	Player(Board& board, Colour colour);
	Player();
	Colour getColour() const;
	std::vector<Piece*> getPieces();
	void printPieces();
	void setCheckStatus();
	bool isInCheck();
	void deletePiece(Piece* piece);
	void addPiece(Piece* piece);
};