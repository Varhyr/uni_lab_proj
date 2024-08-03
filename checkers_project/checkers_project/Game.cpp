#include "Game.h"

#include <iostream>



Game::Game() : p1(Player(true, this)), p2(Player(false, this)), b1(Board())
{
	p1.set_oponnent(&p2);
	p2.set_oponnent(&p1);
}

void Game::play()
{
	for (;;) {
		b1.show_graphics();
		p1.your_turn();
		if (p2.show_counter() == 0) {
			b1.show_graphics();
			std::cout<<"Player 1 won"<<std::endl;
			break;
		}
		b1.show_graphics();
		p2.your_turn();
		if (p1.show_counter() == 0) {
			b1.show_graphics();
			std::cout << "Player 2 won" << std::endl;
			break;
		}
		
	}
}

void Game::take_piece(bool is_p1, bool is_queen, int initial_row, int initial_column, int destination_row, int destination_column,int take_row , int take_column)
{
	b1.rm_p(is_p1, initial_row, initial_column);
	b1.rm_p(!is_p1, take_row, take_column);
	b1.add_p(is_p1,is_queen, destination_row, destination_column);
}

void Game::move_piece(bool is_p1,bool is_queen, int initial_row, int initial_column, int destination_row, int destination_column)
{
	b1.rm_p(is_p1, initial_row, initial_column);
	b1.add_p(is_p1, is_queen, destination_row, destination_column);
}
