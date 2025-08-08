#include <iostream>
#include "Piece.h"
#include "Board.h"
#include "Player.h"



bool validateSquare(std::string& square) {
	if (square.size() != 2) return false;
	char x, y;
	x = square[0]; y = square[1];
	return (x >= 'a' && x <= 'h' && y >= '1' && y <= '8');
}

Piece* pieceSelection(Board& board, Player& player) {
	Piece* input;
	while (true) {
		std::string piece;
		std::cin >> piece; //square (ex f5, a2)
		int x, y;
		if (validateSquare(piece)) {
			x = piece[0] - 'a';
			y = piece[1] - '1';
			input = board.getPieceAt(x, y);
			if (input == nullptr) {
				std::cout << "There is no piece on that square.\n";
			}
			else if (input->getPieceColour() != player.getColour()) {
				std::cout << "Piece: " << input->getPieceType() << "\n";
				std::cout << "Not your piece.\n";
			}
			else break;
		}
	}
	return input;
}

void moveSelection(Piece* piece, std::vector<std::pair<int, int>>& possibleMoves, Board& board) {
	int x, y;
	while (true) {
		std::string moveInput;
		std::cin >> moveInput;
		if (validateSquare(moveInput)) {
			x = moveInput[0] - 'a';
			y = moveInput[1] - '1';
			auto move = std::make_pair(x, y);
			if (std::find(possibleMoves.begin(), possibleMoves.end(), move) != possibleMoves.end()) {
				board.movePiece(piece, x, y);
				board.showBoard();
				return;
			}
			std::cout << "That move isn't available for this piece!\n";
		}
		else std::cout << "Invalid square\n";
	}
}

void game(Board& board, std::vector<Player>& players) {
	int currentPlayer = 0;
	std::vector<Piece*> currentPlayerPieces;
	board.showBoard();
	while (true) {
		int x, y;
		
		std::cout << "Current player colour: " << players[currentPlayer].getColour() << "\n";
		auto kingPos = board.getKingPos(players[currentPlayer].getColour());
		if (board.isSquareAttacked(kingPos.first, kingPos.second, players[currentPlayer].getColour()) ){
			std::cout << "You're in Check!\n";
		}
		currentPlayerPieces = players[currentPlayer].getPieces();
		bool hasMoves = false;
		int i = 0;
		for (auto piece : currentPlayerPieces) {
			int validateX, validateY;
			validateX = piece->getPosition().first;
			validateY = piece->getPosition().second;
			if (validateX >= 0 && validateX < 8 && validateY >= 0 && validateY <8) {

				if (!piece->getPossibleMoves(board, piece->getPosition().first, piece->getPosition().second).empty()) {
					hasMoves = true;
					break;
				}
			}
			else players[currentPlayer].deletePiece(piece);
		}
		if (players[currentPlayer].isInCheck()) {
			if (!hasMoves) {
				std::cout << "Checkmate! " << players[(currentPlayer + 1) % 2].getColour() << " wins!\n";
				break;
			}
		}
		else if (!hasMoves) {
			std::cout << "Draw!\n";
			break;
		}
		Piece* input = pieceSelection(board, players[currentPlayer]);
		x = input->getPosition().first;
		y = input->getPosition().second;
		auto possibleMoves = input->getPossibleMoves(board, x, y);
		while (possibleMoves.size() == 0) {
			std::cout << "Ther are no legal moves for this piece.\n";
			input = pieceSelection(board, players[currentPlayer]);
			possibleMoves = input->getPossibleMoves(board, input->getPosition().first, input->getPosition().second);
		}
		for (int i = 0; i < possibleMoves.size(); i++) {
			std::cout << static_cast<char>('a' + possibleMoves[i].first) << possibleMoves[i].second + 1<< " ";
		}
		std::cout << "\n";
		moveSelection(input, possibleMoves, board);
		if (players[currentPlayer].isInCheck()) {
			players[currentPlayer].setCheckStatus();
		}
		Player& nextP = players[(currentPlayer + 1) % 2];
		if (nextP.getColour() == "WHITE") {
			if (board.isSquareAttacked(board.getKingPos("WHITE").first, board.getKingPos("WHITE").second, players[currentPlayer].getColour())) {
				nextP.setCheckStatus();
			}
		}
		else {
			if (board.isSquareAttacked(board.getKingPos("BLACK").first, board.getKingPos("BLACK").second, players[currentPlayer].getColour())) {
				nextP.setCheckStatus();
			}
		}
		currentPlayer = (currentPlayer + 1) % 2;
	}

}

int main() {
	Board board;
	board.specialSet();
	/*Piece* pawn = board.getPieceAt(3, 3);
	std::vector<std::pair<int, int>> moves = pawn->getPossibleMoves(board, 3, 3);
	char column = 'a';
	for (int i = 0; i < moves.size(); i++) {
		std::cout << static_cast<char>(column + moves[i].first) << moves[i].second + 1 << " ";
	}*/
	Player pWhite(board, "WHITE"), pBlack(board, "BLACK");
	std::vector<Player> Players;
	
	Players.push_back(pWhite);
	Players.push_back(pBlack);
	game(board, Players);
	return 0;
}