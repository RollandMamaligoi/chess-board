#pragma once
#include <string>
enum class PieceType
{
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING
};

enum class Colour
{
	WHITE,
	BLACK
};

std::string pieceTypeToString(PieceType type);
std::string colourToString(Colour colour);

