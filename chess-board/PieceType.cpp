#include "PieceType.h"

std::string pieceTypeToString(PieceType type)
{
	switch (type) {
	case PieceType::PAWN: return "PAWN";
	case PieceType::ROOK: return "ROOK";
	case PieceType::KNIGHT: return "KNIGHT";
	case PieceType::BISHOP: return "BISHOP";
	case PieceType::QUEEN: return "QUEEN";
	case PieceType::KING: return "KING";
	default: return "UNKNOWN";
	}
}

std::string colourToString(Colour colour)
{
	switch (colour) {
	case Colour::WHITE: return "WHITE";
	case Colour::BLACK: return "BLACK";
	default: return "UNKNOWN";
	}
}
