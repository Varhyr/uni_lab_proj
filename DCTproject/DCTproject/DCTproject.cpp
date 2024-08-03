#include <iostream>
#include <vector>
#include "gate.h"
#include "func.h"

int main(int number, char* params[])
{
    std::string circuit, input, output;

    if (number != 6) {
        std::cout << "This is a command line program with switches: \n - u input file with a circuit \n - i input file with inputs \n - o output file with outputs" << std::endl;
        return 0;
    }
    for (int i = 1; i <= 5; i += 2) {
        switch (params[i][1]) {
        case 'u':  circuit=params[i+1]; break;
        case 'i':  input=params[i+1]; break;
        case 'o':  output=params[i+1]; break;
        default: std::cout << "This is a command line program with switches: \n - u input file with a circuit \n - i input file with inputs \n - o output file with outputs" << std::endl;
        }
    }

    std::vector<gate> g;
    std::vector<node> n;
    make_node(n, circuit);
    get_circuit(g, n, circuit);
    calc_out(g, n, input, output);



    return 0;
}


