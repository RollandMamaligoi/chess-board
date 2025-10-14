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

Board Board::operator=(const Board& other)
{
	Board newBoard;
	newBoard.whiteKingPos = other.whiteKingPos;
	newBoard.blackKingPos = other.blackKingPos;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (other.board[i][j]) {
				board[i][j] = other.board[i][j]->copy();
			}
			else board[i][j] = nullptr;
		}
	}
	return newBoard;
}

std::pair<int, int> Board::getKingPos(Colour colour)
{
	if (colour == Colour::WHITE) {
		return whiteKingPos;
	}
	else {
		return blackKingPos;
	}
}

void Board::setBoard()
{
	for (int i = 0; i < 8; i++) {
		board[i][1] = new Pawn(i, 1, Colour::WHITE);
		board[i][6] = new Pawn(i, 6, Colour::BLACK);
	}
	board[0][0] = new Rook(0, 0, Colour::WHITE);
	board[7][0] = new Rook(7, 0, Colour::WHITE);
	board[0][7] = new Rook(0, 7, Colour::BLACK);
	board[7][7] = new Rook(7, 7, Colour::BLACK);

	board[1][0] = new Knight(1, 0, Colour::WHITE);
	board[6][0] = new Knight(6, 0, Colour::WHITE);
	board[1][7] = new Knight(1, 7, Colour::BLACK);
	board[6][7] = new Knight(6, 7, Colour::BLACK);
	
	board[2][0] = new Bishop(2, 0, Colour::WHITE);
	board[5][0] = new Bishop(5, 0, Colour::WHITE);
	board[2][7] = new Bishop(2, 7, Colour::BLACK);
	board[5][7] = new Bishop(5, 7, Colour::BLACK);

	board[3][0] = new Queen(3, 0, Colour::WHITE);
	board[3][7] = new Queen(3, 7, Colour::BLACK);

	board[4][0] = new King(4, 0, Colour::WHITE);
	board[4][7] = new King(4, 7, Colour::BLACK);
	whiteKingPos = { 4 , 0 };
	blackKingPos = { 4 , 7 };
}

void Board::specialSet()
{
	
	board[1][7] = new King(1, 7, Colour::BLACK);
	board[5][5] = new King(5, 5, Colour::WHITE);
	board[6][6] = new Pawn(6, 6, Colour::WHITE);
	board[5][7] = new Rook(5, 7, Colour::BLACK);
	board[7][7] = new Rook(7, 7, Colour::BLACK);
	board[1][1] = new Pawn(1, 1, Colour::BLACK);
	board[0][0] = new Rook(0, 0, Colour::BLACK);
	board[2][0] = new Rook(2, 0, Colour::WHITE);
	blackKingPos = { 1, 7 };
	whiteKingPos = { 5, 5 };
	Piece* wKing = getPieceAt(5, 5);
	wKing->setFirstMove(false);
	Piece* bKing = getPieceAt(1, 7);
	bKing->setFirstMove(false);
	Piece* pawn = getPieceAt(6, 6);
	pawn->setFirstMove(false);
	Piece* Pawn = getPieceAt(1, 1);
	Pawn->setFirstMove(false);
}




void Board::showBoard()
{
	for (int y = 7; y >= 0 ; y--) {
		std::cout << y + 1 << "| ";
		for (int x = 0; x < 8; x++) {
			if (board[x][y] == nullptr) {
				std::cout << ". ";
			}
			else if (board[x][y]->getPieceColour() == Colour::BLACK) {
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

void Board::showBoardBlack()
{
	for (int y = 0; y < 8; y++) {
		std::cout << y + 1 << "| ";
		for (int x = 7; x >= 0; x--) {
			if (board[x][y] == nullptr) {
				std::cout << ". ";
			}
			else if (board[x][y]->getPieceColour() == Colour::BLACK) {
				std::cout << (char)tolower(board[x][y]->getSymbol()) << " ";
			}
			else
				std::cout << board[x][y]->getSymbol() << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "  ----------------\n   ";
	char column = 'h';
	for (int i = 0; i < 8; i++) {
		std::cout << column-- << " ";
	}
	std::cout << std::endl << std::endl;
}

bool Board::isSquareAttacked(int posX, int posY, Colour player) const
{
	
	for (auto dir : xyDir) {
		int x = posX + dir.first, y = posY + dir.second;
		while (x >= 0 && x < 8 && y >= 0 && y < 8 && getPieceAt(x, y) == nullptr) {
			x += dir.first; y += dir.second;
		}
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			Piece* piece = getPieceAt(x, y);
			if(piece->getPieceColour() != player
				&& (piece->getPieceType() == PieceType::QUEEN || piece->getPieceType() == PieceType::ROOK)) {
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
			if( piece->getPieceColour() != player && (piece->getPieceType() == PieceType::QUEEN || piece->getPieceType() == PieceType::BISHOP))
			{
				return true;
			}
		}
	}
	for (auto dir : knightDir) {
		int x = posX + dir.first, y = posY + dir.second;
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			Piece* piece = getPieceAt(x, y);
			if(piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == PieceType::KNIGHT)
				{
					return true;
		}
		}
	}
	if (player == Colour::WHITE) {
		int x1 = posX - 1, x2 = posX + 1, y = posY + 1;
		if (x1 >= 0 && y < 8) {
			Piece* piece = getPieceAt(x1, y); 
			if(piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == PieceType::PAWN)
			{
				return true;
			}
		}
		if (x2 < 8 && y < 8) {
			Piece* piece = getPieceAt(x2, y);
			if(piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == PieceType::PAWN)
			{
				return true;
			}
		}
	}
	else {
		int x1 = posX - 1, x2 = posX + 1, y = posY - 1;
		if (x1 >= 0 && y >= 0) {
			Piece* piece = getPieceAt(x1, y);
			if(piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == PieceType::PAWN)
			{
				return true;
			}
		}
		if (x2 < 8 && y >= 0) {
			Piece* piece = getPieceAt(x2, y);
			if(piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == PieceType::PAWN)
			{
				return true;
			}
		}
	}
	for (auto dir : kingDir) {
		int x = posX + dir.first, y = posY + dir.second;
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			Piece* piece = getPieceAt(x, y);
			if (piece != nullptr && piece->getPieceColour() != player && piece->getPieceType() == PieceType::KING) {
				return true;
			}
		}
	}
	return false;
}

Piece* Board::getPieceAt(int x, int y) const
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
	if (piece->getPieceType() == PieceType::KING) {
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
		if (piece->getPieceColour() == Colour::WHITE) {
			whiteKingPos = { toX, toY };
		}
		else blackKingPos = { toX, toY };
	}
	if (piece->getPieceType() == PieceType::PAWN) { 
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
	if (piece->getPieceType() == PieceType::ROOK) piece->setFirstMove(false);
	if (piece->getPieceType() == PieceType::KING) piece->setFirstMove(false);
	board[pos.first][pos.second] = nullptr;
	board[toX][toY] = piece;
	piece->setPosition(toX, toY);
	std::string move;
	move.push_back(piece->getSymbol());
	move.push_back(static_cast<char>(toX + 97));
	move.push_back(static_cast<char>(toY + '1'));
	if (piece->getPieceColour() == Colour::WHITE) {
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

bool Board::simulateMove(Piece* piece, int toX, int toY, Colour player) const
{
	Board testBoard = *this;
	std::pair<int, int> pos = piece->getPosition();
	Piece* testPiece = testBoard.getPieceAt(pos.first, pos.second);

	testBoard.movePiece(testPiece, toX, toY);
	return testBoard.isSquareAttacked(testBoard.getKingPos(player).first, testBoard.getKingPos(player).second, player);
}
void Board::setPieceAt(int x, int y, Piece* piece)
{
	board[x][y] = piece;
}

std::string Board::lastMove(Colour colour) const
{
	if (colour == Colour::WHITE) return whiteMoveHistory[whiteMoveHistory.size() - 1];
	else return blackMoveHistory[blackMoveHistory.size() - 1];
}

Piece* Board::pawnPromotion(Colour pawnColour, int toX, int toY)
{
	std::cout << "What piece would you like your pawn to be promoted to? N B R Q\n";
	char symb;
	while (true) {
		std::cin >> symb;
		switch (symb) {
		case 'N': {
			return new Knight(toX, toY, pawnColour);
			break;
		}

		case 'B': {
			return new Bishop(toX, toY, pawnColour);
			break;
		}
		case 'R': {
			return new Rook(toX, toY, pawnColour);
			break;
		}
		case 'Q': {
			return new Queen(toX, toY, pawnColour);
			break;
		}
		default: {
			std::cout << "No piece with that symbol exists!\n";
		}
		}
	}
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
