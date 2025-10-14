#pragma once
#include "Board.h"
#include "Player.h"
#include <iostream>
#include <vector>
class Game
{
private:
	Board board;
	std::vector<Player> players;
	bool gameOver = false;
public:
	Game();

	bool validateSquare(const std::string& square);
	Piece* pieceSelection(const Board& board, const Player& player);
	void moveSelection(Piece* piece, Board& board, Player& player);
	bool Moves(const Board& board, Player& player); //checks if player has legal moves
	Piece* ValidatePieceSelection(const Board& board, const Player& player);
	void start();

};

