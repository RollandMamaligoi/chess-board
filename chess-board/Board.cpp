#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "King.h"
#include <iostream>

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

void Board::showBoard()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == nullptr) {
				std::cout << ". ";
			}
			else if (board[i][j]->getPieceColour() == "WHITE") {
					std::cout << (char)tolower(board[i][j]->getSymbol()) << " ";
			}
			else
				std::cout << board[i][j]->getSymbol() << " ";
		}
		std::cout << std::endl;
	}
}
