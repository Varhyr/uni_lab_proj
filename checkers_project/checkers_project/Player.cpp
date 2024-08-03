#include "Player.h"
#include "Game.h"
#include <iostream>
#include <utility>


void Player::be_taken(int row, int column)
{
	counter--;
	for (int i = 0; i < 12; ++i) {
		if (pwn[i]->ret_row() == row && pwn[i]->ret_column() == column) {
			
			
			pwn[i]->move(0,0);

			

		}
	}

}

bool Player::is_move_valid(int initial_row, int initial_column, int destination_row, int destination_column)
{
	
	for (int i = 0; i < 12; ++i) {
		if (pwn[i]->ret_row() == initial_row && pwn[i]->ret_column() == initial_column) {

			if (pwn[i]->is_valid(destination_row, destination_column)) {
				if (dynamic_cast<Pawn*>(pwn[i]) == nullptr)
					game->move_piece(is_p1,true, initial_row, initial_column, destination_row, destination_column);
				else
					game->move_piece(is_p1,false, initial_row, initial_column, destination_row, destination_column);
				pwn[i]->move(destination_row, destination_column);
				return true;
			}
			if (pwn[i]->is_take_valid(destination_row, destination_column)) {
				int where_to_go_row = whereToGo_row(initial_row, destination_row);
				int where_to_go_column = whereToGo_column(initial_column, destination_column);
				if (dynamic_cast<Pawn*>(pwn[i]) == nullptr)
					game->take_piece(is_p1, true, initial_row, initial_column, where_to_go_row, where_to_go_column, destination_row, destination_column);
				else
					game->take_piece(is_p1, false, initial_row, initial_column, where_to_go_row, where_to_go_column, destination_row, destination_column);
				pwn[i]->move(where_to_go_row, where_to_go_column);
				oponnent->be_taken(destination_row, destination_column);
				return true;
			}
			else
				return false;

		}

	}
	std::cout << "Input error: you chose nonexisting or oponent's piece\n";
	return false;
}

int Player::whereToGo_row(int initial_row, int destination_row)
{
	if (initial_row < destination_row)
		return destination_row + 1;
	else
		return destination_row - 1;
}

int Player::whereToGo_column(int initial_column, int destination_column)
{
	if (initial_column < destination_column)
		return destination_column + 1;
	else
		return destination_column - 1;
}




Player::Player(const bool p1, Game* g): counter(12), game(g), is_p1(p1)
{
	if (is_p1) {
		pwn[0] = (new Pawn(1, 1, this));
		game->add_pwn(is_p1, 1, 1);
		pwn[1] = (new Pawn(1, 3, this));
		game->add_pwn(is_p1, 1, 3);
		pwn[2] = (new Pawn(1, 5, this));
		game->add_pwn(is_p1, 1, 5);
		pwn[3] = (new Pawn(1, 7, this));
		game->add_pwn(is_p1, 1, 7);
		pwn[4] = (new Pawn(2, 2, this));
		game->add_pwn(is_p1, 2, 2);
		pwn[5] = (new Pawn(2, 4, this));
		game->add_pwn(is_p1, 2, 4);
		pwn[6] = (new Pawn(2, 6, this));
		game->add_pwn(is_p1, 2, 6);
		pwn[7] = (new Pawn(2, 8, this));
		game->add_pwn(is_p1, 2, 8);
		pwn[8] = (new Pawn(3, 1, this));
		game->add_pwn(is_p1, 3, 1);
		pwn[9] = (new Pawn(3, 3, this));
		game->add_pwn(is_p1, 3, 3);
		pwn[10] = (new Pawn(3, 5, this));
		game->add_pwn(is_p1, 3, 5);
		pwn[11] = (new Pawn(3, 7, this));
		game->add_pwn(is_p1, 3, 7);
	}
	else {
		pwn[0] = (new Pawn(8, 8, this));
		game->add_pwn(is_p1, 8, 8);
		pwn[1] = (new Pawn(8, 6, this));
		game->add_pwn(is_p1, 8, 6);
		pwn[2] = (new Pawn(8, 4, this));
		game->add_pwn(is_p1, 8, 4);
		pwn[3] = (new Pawn(8, 2, this));
		game->add_pwn(is_p1, 8, 2);
		pwn[4] = (new Pawn(7, 7, this));
		game->add_pwn(is_p1, 7, 7);
		pwn[5] = (new Pawn(7, 5, this));
		game->add_pwn(is_p1, 7, 5);
		pwn[6] = (new Pawn(7, 3, this));
		game->add_pwn(is_p1, 7, 3);
		pwn[7] = (new Pawn(7, 1, this));
		game->add_pwn(is_p1, 7, 1);
		pwn[8] = (new Pawn(6, 8, this));
		game->add_pwn(is_p1, 6, 8);
		pwn[9] = (new Pawn(6, 6, this));
		game->add_pwn(is_p1, 6, 6);
		pwn[10] = (new Pawn(6, 4, this));
		game->add_pwn(is_p1, 6, 4);
		pwn[11] = (new Pawn(6, 2, this));
		game->add_pwn(is_p1, 6, 2);
	}
}
Player::~Player()
{
	for (auto& p : pwn)
		delete p;
}
int Player::show_counter()
{
	return counter;
}
void Player::set_oponnent(Player* op)
{
	oponnent = op;
}

void Player::your_turn()
{
	int initial_row = 0;
	int initial_column = 0;
	int destination_row = 0;
	int destination_column = 0;
	do {
		std::cout << "Enter your move:" << std::endl;
		std::cin >> initial_row;			
		std::cin >> initial_column;
		std::cin >> destination_row;
		std::cin >> destination_column;

	} while (!(is_move_valid(initial_row, initial_column, destination_row, destination_column) ));


	for (int i = 0; i < 12; ++i) {
		if (pwn[i]->ret_row()== 8 && is_p1 || pwn[i]->ret_row() == 1 && !is_p1) {
			if (dynamic_cast<Pawn*>(pwn[i]) != nullptr) {
				//promote
				int position_row = pwn[i]->ret_row();
				int position_column = pwn[i]->ret_column();
				
				delete pwn[i];
				pwn[i] = new Queen(position_row, position_column,this);
				game->move_piece(is_p1, true, position_row, position_column, position_row, position_column);

			}
		}
	}

	
	
}


