#pragma once
#include "Player.h"
#include "Board.h"
class Game
{
	Board b1;
	Player p1;
	Player p2;

public:

	Game();
	void add_pwn(bool is_p1, int row, int column) { b1.add_p(is_p1, false, row, column); }
	void move_piece(bool is_p1, bool is_queen, int initial_row, int initial_column, int destination_row, int destination_column);
	void take_piece(bool is_p1, bool is_queen, int initial_row, int initial_column, int destination_row, int destination_column, int take_row, int take_column);
	int get_sqr_state(int row, int column) { return b1.get_sqr_state(row, column); }
	void play();

};


