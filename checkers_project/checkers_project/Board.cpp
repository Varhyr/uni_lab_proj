#include "Board.h"
#include<Windows.h>
#include<iostream>


void Board::show_graphics()
{
	system("cls");


	for (int i = 1; i < 9; i++) {
		std::cout << "---------------------------------\n";
		for (int ii = 1; ii < 9; ii++) {
			std::cout << "| "<< board[i][ii].ret_graphics()<<" ";

		}
		std::cout << "|\n";
	}
	std::cout << "---------------------------------\n";
}

void Board::add_p(bool player, bool is_queen, int row, int column)
{
	if (player) 
		if(is_queen)
			board[row][column].set_state(2);
		else 
			board[row][column].set_state(1);
	else
		if (is_queen)
			board[row][column].set_state(-2);
		else
			board[row][column].set_state(-1);
}

void Board::rm_p(bool player, int row, int column)
{
		board[row][column].set_state(0); 

}

char squere::ret_graphics()
{
	if (sqr_state == 0)
		return ' ';
	if (sqr_state == 1)
		return '+';
	if (sqr_state == 2)
		return '#';
	if (sqr_state == -1)
		return 'o';
	if (sqr_state == -2)
		return '@';
	else
		return 0;

}
