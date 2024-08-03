#pragma once


class squere {
	int sqr_state = 0; // 0 - empty sqr, 1 - pawn, 2 - queen, positive is p1 , negative is p2
public:
	int get_state() { return sqr_state; }
	void set_state(int on_sqr) { sqr_state = on_sqr; }
	char ret_graphics();
};

class Board 
{
	squere board[9][9];
public:
	void show_graphics();
	void add_p(bool player, bool is_queen, int row, int column);
	void rm_p(bool player, int row, int column);
	int get_sqr_state(int row, int column) { return board[row][column].get_state(); }

};

