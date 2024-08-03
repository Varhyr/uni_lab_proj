#include "Queen.h"
#include "Player.h"
#include "Game.h"
#include<iostream>

bool Queen::is_valid(int row, int column)
{
	// if on board
	if (row < 1 || column < 1 || row > 8 || column>8) {
		std::cout << "Board is 8x8\n";
		return false;
	}
	// if move is diagonal
	if ((Piece::ret_row() - Piece::ret_column()) != (row - column) && (Piece::ret_row() + Piece::ret_column()) != (row + column)) {
		std::cout << "Sqrs do not lie on the same diagonal\n";
		return false;
	}
	
	// if move is legal with current board state
	int i = 1;
	if(Piece::ret_row()< row && Piece::ret_column()< column)
		
		while (Piece::ret_row() + i <= row && Piece::ret_column() + i <= column) {
			if (Piece::get_player()->get_game()->get_sqr_state(row, column) != 0) {

				std::cout << "Something between\n";
				return false;
			}

		i++;
		}
	if (Piece::ret_row() < row && Piece::ret_column() > column)

		while (Piece::ret_row() + i <= row && Piece::ret_column() - i >= column) {
			if (Piece::get_player()->get_game()->get_sqr_state(row, column) != 0) {

				std::cout << "Something between\n";
				return false;
			}

			i++;
		}
	if (Piece::ret_row() > row && Piece::ret_column() < column)

		while (Piece::ret_row() - i >= row && Piece::ret_column()+ i <= column) {
			if (Piece::get_player()->get_game()->get_sqr_state(row, column) != 0) {

				std::cout << "Something between\n";
				return false;
			}

			i++;
		}
	if (Piece::ret_row() > row && Piece::ret_column()> column)

		while (Piece::ret_row() - i >= row && Piece::ret_column()- i >= column) {
			if (Piece::get_player()->get_game()->get_sqr_state(row, column) != 0) {

				std::cout << "Something between\n";
				return false;
			}

			i++;
		}
	
	return true;
}

bool Queen::is_take_valid(int row, int column)
{
	// if on board
	if (row < 1 || column < 1 || row > 8 || column>8) {
		std::cout << "Board is 8x8\n";
		return false;
	}
	// if move is diagonal
	if ((Piece::ret_row() - Piece::ret_column()) != (row - column) && (Piece::ret_row() + Piece::ret_column()) != (row + column)) {
		std::cout << "Sqrs do not lie on the same diagonal\n";
		return false;
	}

	if (Piece::get_player()->ret_is_p1()) {
		if (Piece::get_player()->get_game()->get_sqr_state(row, column) > 0) {

			std::cout << "Can't take: your piece on sqr\n";
			return false;
		}
		int behind_row = Piece::get_behind_row(Piece::ret_row(), row);
		int behind_column = Piece::get_behind_column(Piece::ret_column(), column);
		if (behind_row < 1 || behind_column < 1 || behind_row>8 || behind_column>8) {
			std::cout << "No sqr behind";
			return false;
		}
		if (Piece::get_player()->get_game()->get_sqr_state(behind_row, behind_column) != 0) {

			std::cout << "Something behind sqr\n";
			return false;
		}
	}
	else {
		if (Piece::get_player()->get_game()->get_sqr_state(row, column) > 0) {

			std::cout << "Can't take: your piece on sqr\n";
			return false;
		}
		int behind_row = Piece::get_behind_row(Piece::ret_row(), row);
		int behind_column = Piece::get_behind_column(Piece::ret_column(), column);
		if (Piece::get_player()->get_game()->get_sqr_state(behind_row, behind_column) != 0) {

			std::cout << "Something behind sqr\n";
			return false;
		}
	}
	return true;
}
