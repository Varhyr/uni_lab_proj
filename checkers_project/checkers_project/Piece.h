#pragma once
class Player; 

class Piece
{
	Player* player = nullptr;
	int row = 0;
	int column = 0;
protected:
	int get_behind_row(int initial_row, int destination_row);
	int get_behind_column( int initial_column,  int destination_column);
public:
	virtual bool is_valid(int row, int column) = 0;
	virtual bool is_take_valid(int row, int column) = 0;
	void set_player(Player* p) { player = p; }
	Player* get_player() { return player; }
	void move(int row, int column);
	int ret_row() { return row; }
	int ret_column() { return column; }

};

