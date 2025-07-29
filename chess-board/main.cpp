#include <iostream>
#include "Piece.h"
#include "Board.h"



int main() {
	Board board;
	board.specialSet();
	board.showBoard();
	Piece* pawn = board.getPieceAt(3, 3);
	std::vector<std::pair<int, int>> moves = pawn->getPossibleMoves(board, 3, 3);
	char column = 'a';
	for (int i = 0; i < moves.size(); i++) {
		std::cout << static_cast<char>(column + moves[i].first) << moves[i].second + 1 << " ";
	}
	return 0;
}