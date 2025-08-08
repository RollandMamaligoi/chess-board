#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"
#include "Player.h"
#include <iostream>
namespace {
	static const std::vector<std::pair<int, int>> xyDir = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
	static const std::vector<std::pair<int, int>> diagonalDir = { { 1, 1 }, { 1, -1 }, { -1, -1 }, { -1, 1 } };
	static const std::vector<std::pair<int, int>> knightDir = { {1, 2}, {2 , 1} , {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2 } };
	static const std::vector<std::pair<int, int>> kingDir = { {0, 1} , {1,1},{1,0},{1, -1},{0, -1},{-1, -1},{-1, 0}, {-1, 1} };
}

Board::Board() : board(8, std::vector<Piece*>(8, nullptr)) {};

Board::~Board()
{
	for (auto& row : board) {
		for (auto piece : row) {
			delete piece;
		}
	}
}

std::pair<int, int> Board::getKingPos(std::string colour)
{
	if (colour == "WHITE") {
		return whiteKingPos;
	}
	else {
		return blackKingPos;
	}
}

void Board::setBoard()
{
	for (int i = 0; i < 8; i++) {
		board[i][1] = new Pawn(i, 1, "WHITE");
		board[i][6] = new Pawn(i, 6, "BLACK");
	}
	board[0][0] = new Rook(0, 0, "WHITE");
	board[7][0] = new Rook(7, 0, "WHITE");
	board[0][7] = new Rook(0, 7, "BLACK");
	board[7][7] = new Rook(7, 7, "BLACK");

	board[1][0] = new Knight(1, 0, "WHITE");
	board[6][0] = new Knight(6, 0, "WHITE");
	board[1][7] = new Knight(1, 7, "BLACK");
	board[6][7] = new Knight(6, 7, "BLACK");
	
	board[2][0] = new Bishop(2, 0, "WHITE");
	board[5][0] = new Bishop(5, 0, "WHITE");
	board[2][7] = new Bishop(2, 7, "BLACK");
	board[5][7] = new Bishop(5, 7, "BLACK");

	board[3][0] = new Queen(3, 0, "WHITE");
	board[3][7] = new Queen(3, 7, "BLACK");

	board[4][0] = new King(4, 0, "WHITE");
	board[4][7] = new King(4, 7, "BLACK");
	whiteKingPos = { 4 , 0 };
	blackKingPos = { 4 , 7 };
}

void Board::specialSet()
{
	
	board[7][7] = new King(7, 7, "BLACK");
	board[0][0] = new King(0, 0, "WHITE");
	board[6][2] = new Queen(6, 2, "WHITE");
	blackKingPos = { 7, 7 };
	whiteKingPos = { 0, 0 };
	Piece* wKing = getPieceAt(0, 0);
	wKing->setFirstMove(false);
	Piece* bKing = getPieceAt(7, 7);
	bKing->setFirstMove(false);
}




void Board::showBoard()
{
	for (int y = 7; y >= 0 ; y--) {
		std::cout << y + 1 << "| ";
		for (int x = 0; x < 8; x++) {
			if (board[x][y] == nullptr) {
				std::cout << ". ";
			}
			else if (board[x][y]->getPieceColour() == "BLACK") {
					std::cout << (char)tolower(board[x][y]->getSymbol()) << " ";
			}
			else
				std::cout << board[x][y]->getSymbol() << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "  ----------------\n   ";
	char column = 'a';
	for (int i = 0; i < 8; i++) {
		std::cout << column++ << " ";
	}
	std::cout << std::endl << std::endl;
}

bool Board::isSquareAttacked(int posX, int posY, const std::string& player)
{
	
	for (auto dir : xyDir) {
		int x = posX + dir.first, y = posY + dir.second;
		while (x >= 0 && x < 8 && y >= 0 && y < 8 && getPieceAt(x, y) == nullptr) {
			x += dir.first; y += dir.second;
		}
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			Piece* piece = getPieceAt(x, y);
			if(piece->getPieceColour() != player
				&& (piece->getPieceType() == "QUEEN" || piece->getPieceType() == "ROOK")) {
					return true;
			}
		}
	}
	for (auto dir : diagonalDir) {
		int x = posX + dir.first; int y = posY + dir.second;
		while (x >= 0 && x < 8 && y >= 0 && y < 8 && getPieceAt(x, y) == nullptr) {
			x += dir.first, y += dir.second;
		}
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			Piece* piece = getPieceAt(x, y);
			if( piece->getPieceColour() != player && (piece->getPieceType() == "QUEEN" || piece->getPieceType() == "BISHOP"))
			{
				return true;
			}
		}
	}
	for (auto dir : knightDir) {
		int x = posX + dir.first, y = posY + dir.second;
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			Piece* piece = getPieceAt(x, y);
			if(piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == "KNIGHT")
				{
					return true;
		}
		}
	}
	if (player == "WHITE") {
		int x1 = posX - 1, x2 = posX + 1, y = posY + 1;
		if (x1 >= 0 && y < 8) {
			Piece* piece = getPieceAt(x1, y); 
			if(piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == "PAWN")
			{
				return true;
			}
		}
		if (x2 < 8 && y < 8) {
			Piece* piece = getPieceAt(x2, y);
			if(piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == "PAWN")
			{
				return true;
			}
		}
	}
	else {
		int x1 = posX - 1, x2 = posX + 1, y = posY - 1;
		if (x1 >= 0 && y >= 0) {
			Piece* piece = getPieceAt(x1, y);
			if(piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == "PAWN")
			{
				return true;
			}
		}
		if (x2 < 8 && y >= 0) {
			Piece* piece = getPieceAt(x2, y);
			if(piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == "PAWN")
			{
				return true;
			}
		}
	}
	for (auto dir : kingDir) {
		int x = posX + dir.first, y = posY + dir.second;
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			Piece* piece = getPieceAt(x, y);
			if (piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == "KING") {
				return true;
			}
		}
	}
	return false;
}

Piece* Board::getPieceAt(int x, int y)
{
	return board[x][y];
}

void Board::movePiece(Piece* piece, int toX, int toY) 
{
	bool shortCastle = false, longCastle = false;
	Piece* enemyPiece = getPieceAt(toX, toY);
	if (enemyPiece != nullptr) {
		delete enemyPiece;
		enemyPiece = nullptr;
	}
	std::pair<int, int> pos = piece->getPosition();
	if (piece->getPieceType() == "KING") {
		if (pos.first - toX == 2) {
			Piece* rook = getPieceAt(pos.first - 4, pos.second);
			if (rook != nullptr) {
				board[pos.first - 1][pos.second] = rook;
				board[pos.first - 4][pos.second] = nullptr;
				rook->setPosition(pos.first - 1, pos.second);
				longCastle = true;
			}
		}
		if (pos.first - toX == -2) {
			Piece* rook = getPieceAt(pos.first + 3, pos.second);
			if (rook != nullptr) {
				board[pos.first + 3][pos.second] = nullptr;
				board[pos.first + 1][pos.second] = rook;
				rook->setPosition(pos.first + 1, pos.second);
				shortCastle = true;
			}
		}
		if (piece->getPieceColour() == "WHITE") {
			whiteKingPos = { toX, toY };
		}
		else blackKingPos = { toX, toY };
	}
	if (piece->getPieceType() == "PAWN") { 
		piece->setFirstMove(false); 
		if (pos.first + 1 == toX) {
			delete board[pos.first + 1][pos.second];
			board[pos.first + 1][pos.second] = nullptr;
		}
		else if (pos.first - 1 == toX) {
			delete board[pos.first - 1][pos.second];
			board[pos.first - 1][pos.second] = nullptr;
		}
	}
	if (piece->getPieceType() == "ROOK") piece->setFirstMove(false);
	if (piece->getPieceType() == "KING") piece->setFirstMove(false);
	board[pos.first][pos.second] = nullptr;
	board[toX][toY] = piece;
	piece->setPosition(toX, toY);
	std::string move;
	move.push_back(piece->getSymbol());
	move.push_back(static_cast<char>(toX + 97));
	move.push_back(static_cast<char>(toY + '1'));
	if (piece->getPieceColour() == "WHITE") {
		if (shortCastle) {
			whiteMoveHistory.push_back("O-O");
		}
		else if (longCastle) {
			whiteMoveHistory.push_back("O-O-O");
		}
		else whiteMoveHistory.push_back(move);
	}
	else {
		if (shortCastle) {
			blackMoveHistory.push_back("O-O");
		}
		else if (longCastle) {
			blackMoveHistory.push_back("O-O-O");
		}
		else blackMoveHistory.push_back(move);
	}
}

bool Board::simulateMove(Piece* piece, int toX, int toY, std::string player)
{
	Board testBoard = *this;
	std::pair<int, int> pos = piece->getPosition();
	Piece* testPiece = testBoard.getPieceAt(pos.first, pos.second);

	testBoard.movePiece(testPiece, toX, toY);
	if (player == "WHITE") {
		return testBoard.isSquareAttacked(testBoard.whiteKingPos.first, testBoard.whiteKingPos.second, "WHITE");
	}
	else return testBoard.isSquareAttacked(testBoard.blackKingPos.first, testBoard.blackKingPos.second, "BLACK");
}
void Board::setPieceAt(int x, int y, Piece* piece)
{
	board[y][x] = piece;
}

std::string Board::lastMove(std::string colour)
{
	if (colour == "WHITE") return whiteMoveHistory[whiteMoveHistory.size() - 1];
	else return blackMoveHistory[blackMoveHistory.size() - 1];
}



Board::Board(const Board& copyRef) : board(8, std::vector<Piece*>(8, nullptr))
{
	whiteKingPos = copyRef.whiteKingPos;
	blackKingPos = copyRef.blackKingPos;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (copyRef.board[i][j]) {
				board[i][j] = copyRef.board[i][j]->copy();
			}
			else board[i][j] = nullptr;
		}
	}
}
