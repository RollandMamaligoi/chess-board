#pragma once
class Piece;
#include <vector>
#include <string>

class Board {
protected:
	std::vector<std::vector<Piece*>> board;
public:
	Board();
	~Board();

	void setBoard();
	void specialSet(); //for debugging only
	void showBoard();
	bool isSquareAttacked(int posX, int posY, std::string player);
	Piece* getPieceAt(int x, int y);
	void movePiece();
};
