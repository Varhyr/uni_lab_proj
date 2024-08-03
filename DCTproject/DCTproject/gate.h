#pragma once
#include <vector>
struct node
{
	bool value = 0;
	bool full = false;
	bool input = false;
	bool output = false;
	int prev;

};
struct gate
{
	char type = 0;
	int input_a;
	int input_b;
	int output;

	void execute(std::vector<node>& n);
	gate();
};



