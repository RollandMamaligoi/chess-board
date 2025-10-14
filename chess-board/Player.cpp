#include "Player.h"
#include "Piece.h"
#include "Board.h"
#include <iostream>

Player::Player(Board& board, Colour colour)
{
	this->colour = colour;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Piece* piece = board.getPieceAt(i, j);
			if (piece != nullptr && piece->getPieceColour() == colour)
				Pieces.push_back(piece);
		}
	}
}

Player::Player()
{
	this->colour = Colour::WHITE;
	Pieces = {};
}



Colour Player::getColour() const
{
	return colour;
}

std::vector<Piece*> Player::getPieces()
{
	return Pieces;
}

void Player::printPieces()
{
	for (int i = 0; i < Pieces.size(); i++) {
		if (colourToString(Pieces[i]->getPieceColour()) == "BLACK") {
			std::cout << (char)tolower(Pieces[i]->getSymbol()) << " ";
		}
		else {
			std::cout << Pieces[i]->getSymbol() << " ";
		}
	}
}

void Player::setCheckStatus()
{
	check = !check;
}

bool Player::isInCheck()
{
	return check;
}

void Player::deletePiece(Piece* piece)
{
	int i = 0;
	for (auto p : Pieces) {
		if (p == piece) {
			Pieces.erase(Pieces.begin() + i);
		}

		else i++;
	}
}

void Player::addPiece(Piece* piece)
{
	Pieces.push_back(piece);
}


