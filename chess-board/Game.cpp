#include "Game.h"
#include "Piece.h"
Game::Game()
{
	board.setBoard();
	players.push_back(Player(board, Colour::WHITE));
	players.push_back(Player(board, Colour::BLACK));
	gameOver = false;
}

bool Game::validateSquare(const std::string& square)
{
	if (square.size() != 2) return false;
	char x, y;
	x = square[0]; y = square[1];
	return (x >= 'a' && x <= 'h' && y >= '1' && y <= '8');
}

Piece* Game::pieceSelection(const Board& board, const Player& player)
{
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
			else if (colourToString(input->getPieceColour()) != colourToString(player.getColour())) {
				std::cout << "Piece: " << pieceTypeToString(input->getPieceType()) << "\n";
				std::cout << "Not your piece.\n";
			}
			else break;
		}
	}
	return input;
}

void Game::moveSelection(Piece* piece, Board& board, Player& player)
{
	int x, y;
	while (true) {
		auto possibleMoves = piece->getPossibleMoves(board, piece->getPosition().first, piece->getPosition().second);
		std::string moveInput;
		std::cin >> moveInput;
		if (validateSquare(moveInput)) {
			x = moveInput[0] - 'a';
			y = moveInput[1] - '1';
			auto move = std::make_pair(x, y);
			if (std::find(possibleMoves.begin(), possibleMoves.end(), move) != possibleMoves.end()) {
				board.movePiece(piece, x, y);
				if (piece->getPieceType() == PieceType::PAWN) {
					if (y == 7 || y == 0) {
						Piece* promotedPawn = board.pawnPromotion(piece->getPieceColour(), x, y);
						player.deletePiece(piece);
						player.addPiece(promotedPawn);
						board.setPieceAt(x, y, promotedPawn);
					}
				}

				if (piece->getPieceColour() != Colour::WHITE) {
					board.showBoard();
				}
				else {
					board.showBoardBlack();
				}
				return;
			}
			std::cout << "That move isn't available for this piece!\n";
		}
		else std::cout << "Invalid square\n";
	}
}

bool Game::Moves(const Board& board, Player& player)
{
	std::vector<Piece*> currentPlayerPieces = player.getPieces();
	bool hasMoves = false;
	int i = 0;
	for (auto piece : currentPlayerPieces) {
		int validateX, validateY;
		validateX = piece->getPosition().first;
		validateY = piece->getPosition().second;
		if(validateX < 0 || validateX > 7 || validateY < 0 || validateY > 7) {
			player.deletePiece(piece);
			continue;
		}
		if (!piece->getPossibleMoves(board, piece->getPosition().first, piece->getPosition().second).empty()) {
			hasMoves = true;
			break;
		}
		else player.deletePiece(piece);
	}
	return hasMoves;
}

Piece* Game::ValidatePieceSelection(const Board& board, const Player& player)
{
	Piece* input = pieceSelection(board, player);
	int x = input->getPosition().first;
	int y = input->getPosition().second;
	auto possibleMoves = input->getPossibleMoves(board, x, y);
	while (possibleMoves.size() == 0) {
		std::cout << "There are no legal moves for this piece.\n";
		input = pieceSelection(board, player);
		possibleMoves = input->getPossibleMoves(board, input->getPosition().first, input->getPosition().second);
	}
	for (int i = 0; i < possibleMoves.size(); i++) {
		std::cout << static_cast<char>('a' + possibleMoves[i].first) << possibleMoves[i].second + 1 << " ";
	}
	std::cout << "\n";
	return input;
}

void Game::start()
{
	bool currentPlayer = false; //false for white, true for black;
	board.showBoard();
	while (!gameOver) {
		std::vector<Piece*> currentPlayerPieces;
		std::cout << "Current player colour: " << colourToString(players[currentPlayer].getColour()) << "\n";
		auto kingPos = board.getKingPos(players[currentPlayer].getColour());
		if (board.isSquareAttacked(kingPos.first, kingPos.second, players[currentPlayer].getColour())) {
			std::cout << "You're in Check!\n";
		}
		currentPlayerPieces = players[currentPlayer].getPieces();
		bool hasMoves = Moves(board, players[currentPlayer]);
		if (players[currentPlayer].isInCheck()) {
			if (!hasMoves) {
				std::cout << "Checkmate! " << colourToString(players[!currentPlayer].getColour()) << " wins!\n";
				gameOver = true;
				break;
			}
		}
		else if (!hasMoves) {
			std::cout << "Draw!\n";
			break;
		}
		Piece* input = ValidatePieceSelection(board, players[currentPlayer]);
		moveSelection(input, board, players[currentPlayer]);
		if (players[currentPlayer].isInCheck()) {
			players[currentPlayer].setCheckStatus();
		}
		Player& nextP = players[!currentPlayer];
		if (nextP.getColour() == Colour::WHITE) {
			if (board.isSquareAttacked(board.getKingPos(Colour::WHITE).first, board.getKingPos(Colour::WHITE).second, nextP.getColour())) {
				nextP.setCheckStatus();
			}
		}
		else {
			if (board.isSquareAttacked(board.getKingPos(Colour::BLACK).first, board.getKingPos(Colour::BLACK).second, nextP.getColour())) {
				nextP.setCheckStatus();
			}
		}
		currentPlayer = !currentPlayer;
	}
}
