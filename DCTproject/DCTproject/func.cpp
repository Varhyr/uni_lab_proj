#include "func.h"
#include <iostream>
#include <fstream>
#include "gate.h"
#include <sstream> 
#include <vector>
#include <thread>



void make_node(std::vector<node>& n)
{
	std::ifstream file;
	std::string line, type;
	std::istringstream iss;
	file.open("circuit.txt");
	if (!file) {
		std::cerr << "fail to load the file";
		exit(0);
	}
	while (!file.eof()) {
		std::getline(file, line);
		if (file.good()) {
			iss.clear();
			iss.str(line);
			if (iss.good()) {

				iss >> type;


				if (type == "in:" || type == "IN:")
				{
					while (iss >> type) {
						node tmp;
						n.push_back(tmp);
					}
				}
				else if (type == "and" || type == "AND" || type == "or" || type == "OR" || type == "xor" || type == "XOR" || type == "xnor" || type == "XNOR" || type == "nor" || type == "NOR" || type == "nand" || type == "NAND" || type == "not" || type == "NOT")
				{
					node tmp;
					n.push_back(tmp);
				}
			}
		}
	}
	file.close();
}

void get_circuit(std::vector<gate> &g, std::vector<node>& n)
{
	std::ifstream file;
	std::string line, type;
	std::istringstream iss;
	file.open("circuit.txt");
	if (!file) {
		std::cerr << "fail to load the file";
		exit(0);
	}
	while (!file.eof()) {
		std::getline(file, line);
		if (file.good()) {
			iss.clear();
			iss.str(line);
			if (iss.good()) {

				iss >> type;



				if (type == "in:" || type == "IN:")
					add_inputs(iss, n);

				else if (type == "out:" || type == "OUT:")
					add_outputs(iss, n);

				else if (type == "and" || type == "AND")
					add_and(iss, g);
				else if (type == "or" || type == "OR")
					add_or(iss, g);
				else if (type == "xor" || type == "XOR")
					add_xor(iss, g);
				else if (type == "xnor" || type == "XNOR")
					add_xnor(iss, g);

				else if (type == "nor" || type == "NOR")
					add_nor(iss, g);



				else if (type == "nand" || type == "NAND")
					add_nand(iss, g);



				else if (type == "not" || type == "NOT")
					add_not(iss, g);






			}
			
		}
		
	}

	link_prev(n, g);

	file.close();
}

void calc_out(std::vector<gate> &g, std::vector<node>& n)
{
	std::ofstream ofile;
	std::ifstream ifile;
	std::string line, word;
	std::istringstream iss;
	ifile.open("initial.txt");
	ofile.open("output.txt");
	if (!ifile) {
		std::cerr << "fail to load the file";
		exit(0);
	}
	while (!ifile.eof()) {
		std::getline(ifile, line);
		if (ifile.good()) {
			iss.clear();
			iss.str(line);
			if (iss.good()) {

				while (iss >> word) {
					n[(static_cast<std::vector<node, std::allocator<node>>::size_type>((int)word[0]) - int('0'))].value = ((int)word[2] - (int)'0');
					n[(static_cast<std::vector<node, std::allocator<node>>::size_type>((int)word[0]) - int('0'))].full = true;
					
				}

				for (int i = 0; i < n.size(); i++) {
					if (n[i].output) {
						exe_rec(n, g, n[i].prev);
					}
				}
				
				std::string out_str = "IN: " + line + " OUT: ";
				
				for (int i = 0; i < n.size(); i++) {
					if (n[i].output) {
						out_str += std::to_string(i) + ":" + std::to_string(n[i].value) + " ";
					}
				}
				ofile << out_str<<std::endl;
				

			}
		}
	}



	ifile.close();
	ofile.close();
}

void add_inputs(std::istringstream& stream, std::vector<node>& n) {
	std::string word;

	while (stream >> word) {
		n[stoi(word)].input = true;
	}
}
void add_outputs(std::istringstream& stream, std::vector<node>& n) {
	std::string word;
	while (stream >> word) {
		n[stoi(word)].output = true;
	}
	
}

void add_and(std::istringstream& stream, std::vector<gate>& g) {
	std::string word;
	
	

	gate tmp;
	tmp.type = 'a';
	
	stream >> tmp.input_a;
	stream >> tmp.input_b;
	stream >> tmp.output;
	
	g.push_back(tmp);

}
void add_or(std::istringstream& stream, std::vector<gate>& g) {
	std::string word;



	gate tmp;
	tmp.type = 'o';

	stream >> tmp.input_a;
	stream >> tmp.input_b;
	stream >> tmp.output;

	g.push_back(tmp);
}
void add_xor(std::istringstream& stream, std::vector<gate>& g) {
	std::string word;



	gate tmp;
	tmp.type = 'x';

	stream >> tmp.input_a;
	stream >> tmp.input_b;
	stream >> tmp.output;

	g.push_back(tmp);

}
void add_nand(std::istringstream& stream, std::vector<gate>& g) {
	std::string word;



	gate tmp;
	tmp.type = 's';

	stream >> tmp.input_a;
	stream >> tmp.input_b;
	stream >> tmp.output;

	g.push_back(tmp);

}
void add_nor(std::istringstream& stream, std::vector<gate>& g) {
	std::string word;



	gate tmp;
	tmp.type = 'q';

	stream >> tmp.input_a;
	stream >> tmp.input_b;
	stream >> tmp.output;

	g.push_back(tmp);
}
void add_xnor(std::istringstream& stream, std::vector<gate>& g) {
	std::string word;



	gate tmp;
	tmp.type = 'z';

	stream >> tmp.input_a;
	stream >> tmp.input_b;
	stream >> tmp.output;

	g.push_back(tmp);

}
void add_not(std::istringstream& stream, std::vector<gate>& g) {
	std::string word;



	gate tmp;
	tmp.type = 'n';

	stream >> tmp.input_a;
	stream >> tmp.output;
	tmp.input_b = tmp.input_a;
	g.push_back(tmp);

}


std::string get_circuit_file()
{
	
	std::ifstream file;
	std::string line;
	file.open("files.txt");
	if (!file) {
		std::cerr << "fail to load the file";
		exit(0);
	}
	file >> line;
	file.close();
	return line;

}

std::string get_input_file()
{
	
	std::ifstream file;
	std::string line, type;
	std::istringstream iss;
	file.open("files.txt");
	if (!file) {
		std::cerr << "fail to load the file";
		exit(0);
	}
	file >> line;
	file >> line;
	file.close();
	return line;
}

std::string get_output_file()
{

	std::ifstream file;
	std::string line, type;
	std::istringstream iss;
	file.open("files.txt");
	if (!file) {
		std::cerr << "fail to load the file";
		exit(0);
	}
	file >> line;
	file >> line;
	file >> line;
	file.close();
	return line;
}

void input_circuit_file(char* file_name)
{
	std::ifstream ifile;
	std::ofstream ofile;
	std::string lines[3];
	ifile.open("files.txt");
	if (!ifile) {
		std::cerr << "fail to load the file";
		exit(0);
	}
	
	for (int i = 0; i < 3; i++) {
		ifile >> lines[i];
	}

	ifile.close();

	lines[0] = file_name;

	ofile.open("files.txt");
	if (!ofile) {
		std::cerr << "fail to load the file";
		exit(0);
	}

	for (int i = 0; i < 3; i++) {
		ofile << lines[i];
	}

	ofile.close();
}

void input_input_file(char* file_name)
{
	std::ifstream ifile;
	std::ofstream ofile;
	std::string lines[3];
	ifile.open("files.txt");
	if (!ifile) {
		std::cerr << "fail to load the file";
		exit(0);
	}

	for (int i = 0; i < 3; i++) {
		ifile >> lines[i];
	}

	ifile.close();

	lines[1] = file_name;

	ofile.open("files.txt");
	if (!ofile) {
		std::cerr << "fail to load the file";
		exit(0);
	}

	for (int i = 0; i < 3; i++) {
		ofile << lines[i];
	}

	ofile.close();
}

void input_output_file(char* file_name)
{
	std::ifstream ifile;
	std::ofstream ofile;
	std::string lines[3];
	ifile.open("files.txt");
	if (!ifile) {
		std::cerr << "fail to load the file";
		exit(0);
	}

	for (int i = 0; i < 3; i++) {
		ifile >> lines[i];
	}

	ifile.close();

	lines[2] = file_name;

	ofile.open("files.txt");
	if (!ofile) {
		std::cerr << "6fail to load the file";
		exit(0);
	}

	for (int i = 0; i < 3; i++) {
		ofile << lines[i];
	}

	ofile.close();
	std::vector<gate> g;
	std::vector<node> n;
	get_circuit(g, n);
	calc_out(g, n);
}

void exe_rec(std::vector<node>& n, std::vector<gate>& g, int c) {
	if (!n[g[c].input_a].full) {
		exe_rec(n, g, n[g[c].input_a].prev);
	}
	if (!n[g[c].input_b].full) {
		exe_rec(n, g, n[g[c].input_b].prev);
	}
	g[c].execute(n);
}

void link_prev(std::vector<node>& n, std::vector<gate>& g) {
	for (int i = 0 ; i < g.size(); i++) {
		n[g[i].output].prev = i;
	}
}
