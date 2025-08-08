#pragma once
class Piece;
class Player;
#include <vector>
#include <string>

class Board {
protected:
	std::vector<std::vector<Piece*>> board;
	std::pair<int, int> whiteKingPos, blackKingPos;
	std::vector<std::string> whiteMoveHistory, blackMoveHistory;
	bool checkMate = false;
	bool whiteToMove = true;
public:
	Board();
	~Board();

	std::pair<int, int> getKingPos(std::string colour);
	void setBoard();
	void specialSet(); //for debugging only
	void showBoard();
	bool isSquareAttacked(int posX, int posY, const std::string& player);
	Piece* getPieceAt(int x, int y);
	void movePiece(Piece* piece, int toX, int toY);
	bool simulateMove(Piece* piece, int toX, int toY, std::string player);
	void setPieceAt(int x, int y, Piece* piece);
	std::string lastMove(std::string colour);
	Board(const Board& copyRef); //copy constructor
};