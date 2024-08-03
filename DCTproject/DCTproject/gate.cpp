#include "gate.h"
#include "func.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h> // Sleep()
#include <vector>

void gate::execute(std::vector<node>& n)
{
	if (!type) {
		std::cerr << "error no initialisation";
		exit(0);
	}
	
	
		switch (type) {
		case 'o': n[output].value = (n[input_a].value || n[input_b].value); break;									//or
		case 'a': n[output].value = (n[input_a].value && n[input_b].value); break;									//and
		case 'x': if (n[input_a].value == n[input_b].value)n[output].value = 0; else n[output].value = 1; break;	//xor
		case 'q': n[output].value = (!(n[input_a].value || n[input_b].value)); break;								//nor
		case 's': n[output].value = (!(n[input_a].value && n[input_b].value)); break;								//nand
		case 'z': if (n[input_a].value == n[input_b].value)n[output].value = 1; else n[output].value = 0; break;	//xnor
		case 'n': n[output].value = !n[input_a].value; break;														//not
		}
	
		n[output].full = true;
	
	

}

gate::gate() : type(0), input_a(0), input_b(0), output(0){}

