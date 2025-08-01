#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"
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

void Board::setBoard()
{
	for (int i = 0; i < 8; i++) {
		board[1][i] = new Pawn(1, i, "WHITE");
		board[6][i] = new Pawn(6, i, "BLACK");
	}
	board[0][0] = new Rook(0, 0, "WHITE");
	board[0][7] = new Rook(0, 7, "WHITE");
	board[7][0] = new Rook(7, 0, "BLACK");
	board[7][7] = new Rook(7, 7, "BLACK");

	board[0][1] = new Knight(0, 1, "WHITE");
	board[0][6] = new Knight(0, 6, "WHITE");
	board[7][1] = new Knight(7, 1, "BLACK");
	board[7][6] = new Knight(7, 6, "BLACK");
	
	board[0][2] = new Bishop(0, 2, "WHITE");
	board[0][5] = new Bishop(0, 5, "WHITE");
	board[7][2] = new Bishop(7, 2, "BLACK");
	board[7][5] = new Bishop(7, 5, "BLACK");

	board[0][3] = new Queen(0, 3, "WHITE");
	board[7][3] = new Queen(7, 3, "BLACK");

	board[0][4] = new King(0, 4, "WHITE");
	board[7][4] = new King(7, 4, "BLACK");
}

void Board::specialSet()
{
	
	board[3][3] = new King(3, 3, "WHITE");
	board[4][4] = new Knight(4, 4, "WHITE");
	board[0][2] = new Queen(2, 2, "BLACK");
	board[1][5] = new Bishop(1, 5, "WHITE");
	board[4][2] = new Rook(4, 2, "BLACK");
}




void Board::showBoard()
{
	for (int i = 7; i > -1; i--) {
		std::cout << i + 1 << "| ";
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == nullptr) {
				std::cout << ". ";
			}
			else if (board[i][j]->getPieceColour() == "BLACK") {
					std::cout << (char)tolower(board[i][j]->getSymbol()) << " ";
			}
			else
				std::cout << board[i][j]->getSymbol() << " ";
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

bool Board::isSquareAttacked(int posX, int posY, std::string player)
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
	return board[y][x];;
}
