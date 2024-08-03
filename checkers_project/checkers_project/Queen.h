#pragma once
#include "Piece.h"
class Queen :public Piece
{
public:
	Queen(int row, int column, Player* player) { Piece::move(row, column); Piece::set_player(player);}
	bool is_valid(int row, int column) override;
	bool is_take_valid(int row, int column) override;



};

