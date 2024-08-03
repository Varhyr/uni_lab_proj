#include "Player.h"
#include "Pawn.h"
#include "Game.h"
#include<iostream>




int Piece::get_behind_row(int initial_row,  int destination_row)
{
	if (initial_row < destination_row)
		return destination_row + 1;
	else
		return destination_row - 1;
}
int Piece::get_behind_column(int initial_column, int destination_column)
{
	if (initial_column < destination_column)
		return destination_column + 1;
	else
		return destination_column - 1;
}

void Piece::move(int row, int column)
{
	Piece::row = row;
	Piece::column = column;
}



bool Pawn::is_valid(int row, int column)
{
	// if on board
	if (row < 1 || column < 1 || row > 8 || column>8) {
		std::cout << "Board is 8x8\n";
		return false;
	}
	// if move is diagonal
	if (!(row == (Piece::ret_row() + 1) && column == (Piece::ret_column() + 1) || row == (Piece::ret_row() - 1) && (column == Piece::ret_column() - 1) ||
		row == (Piece::ret_row() + 1) && column == (Piece::ret_column() - 1) || row == (Piece::ret_row() - 1) && (column == Piece::ret_column() + 1))) {
		std::cout << "Pawns move only diagonaly by 1 quere\n";
		return false;
	}
	// if move is legal with current board state
	if (Piece::get_player()->get_game()->get_sqr_state(row, column) != 0) {


		return false;
	}
	return true;
}

bool Pawn::is_take_valid(int row, int column)
{
	// if on board
	if (row < 1 || column < 1 || row > 8 || column>8) {
	
		return false;
	}
	// if move is diagonal
	if (!(row == (Piece::ret_row() + 1) && column == (Piece::ret_column() + 1) || row == (Piece::ret_row() - 1) && (column == Piece::ret_column() - 1) ||
		row == (Piece::ret_row() + 1) && column == (Piece::ret_column() - 1) || row == (Piece::ret_row() - 1) && (column == Piece::ret_column() + 1))) {
		
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
		if (Piece::get_player()->get_game()->get_sqr_state(row, column) < 0) {

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
