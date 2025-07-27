#include <iostream>
#include "Piece.h"
#include "Board.h"



int main() {
	Board board;
	board.setBoard();
	board.showBoard();
	Piece* pawn = board.getPieceAt(0, 1);
	std::vector<std::pair<int, int>> moves = pawn->getPossibleMoves(board, 0, 1);
	char column = 'a';
	for (int i = 0; i < moves.size(); i++) {
		std::cout << static_cast<char>(column + moves[i].first) << moves[i].second + 1 << " ";
	}
	return 0;
}