#pragma once
class Piece;
#include <vector>

class Board {
protected:
	std::vector<std::vector<Piece*>> board;
public:
	Board();
	~Board();

	void setBoard();
	void specialSet(); //for debugging only

	void showBoard();

	Piece* getPieceAt(int x, int y);
};
