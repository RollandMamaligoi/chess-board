#pragma once
class Piece;
class Player;
enum class Colour;
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
	Board(const Board& copyRef); //copy constructor
	~Board();

	Board operator=(const Board& other); //copy assignment operator
	std::pair<int, int> getKingPos(Colour colour);
	void setBoard();
	void specialSet(); //for debugging only
	void showBoard();
	void showBoardBlack();
	bool isSquareAttacked(int posX, int posY, Colour player) const;
	Piece* getPieceAt(int x, int y) const;
	void movePiece(Piece* piece, int toX, int toY);
	bool simulateMove(Piece* piece, int toX, int toY, Colour player) const;
	void setPieceAt(int x, int y, Piece* piece);
	std::string lastMove(Colour colour) const;
	Piece* pawnPromotion(Colour pawnColour, int toX, int toY);

};