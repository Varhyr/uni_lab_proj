#pragma once
#include "Queen.h"
#include "Pawn.h"
class Game;
#include <list>

class Player
{
	Game* game;
	Player* oponnent = nullptr;
	int counter;
	Piece* pwn[12];
	const bool is_p1;
	void be_taken(int row, int column);
	bool is_move_valid(int initial_row,	int initial_column,	int destination_row, int destination_column);
	int whereToGo_row(int initial_row, int destination_row);
	int whereToGo_column(int initial_column, int destination_column);
public:
	Player(const bool p1, Game* g = nullptr);
	~Player();
	void set_oponnent(Player* op);
	void your_turn();
	int show_counter();
	Game* get_game() { return game; }
	bool ret_is_p1(){ return is_p1; }
};


