#pragma once
#include "gate.h"
#include <sstream> 
#include <vector>
#include <map>
/**
* @brief Fills node vector with nodes
* @param Vector of nodes to be filled
* @param name of the circuit file
*
*/
void make_node(std::vector<node>& n, std::string& circuit);

/**
* @brief Reads circuit file, calls for apropriate add_ function for every gate/input node/output node in the file and calls for link_prev function
* @param Vector of gates to be filled
* @param Vector of nodes to be linked with gates
* @param name of the circuit file
*
*/
void get_circuit(std::vector<gate>& g, std::vector<node>& n, std::string& circuit);

/**
* @brief Reads input file. For every line prints result to the output file
* @param Filled vector of gates linked with nodes
* @param Filled vector of nodes linked with gates
* @param Name of the input file
* @param Name of the output file
*
*/
void calc_out(std::vector<gate>& g, std::vector<node>& n, std::string& input, std::string& output);

/**
* @brief Adds input flag to gates marked as input in circuit file
* @param stringstream with id of nodes to be flagged
* @param Filled vector of nodes
*
*/
void add_inputs(std::istringstream&, std::vector<node>& n);

/**
* @brief Adds output flag to gates marked as output in circuit file
* @param stringstream with id of nodes to be flagged
* @param Filled vector of nodes
*
*/
void add_outputs(std::istringstream&, std::vector<node>& n);

/**
* @brief Pushes and gate to vector
* @param stringstream with gate description
* @param Vector of gates to be pushed
*
*/
void add_and(std::istringstream&, std::vector<gate>& g);

/**
* @brief Pushes or gate to vector
* @param stringstream with gate description
* @param Vector of gates to be pushed
*
*/
void add_or(std::istringstream&, std::vector<gate>& g);

/**
* @brief Pushes xor gate to vector
* @param stringstream with gate description
* @param Vector of gates to be pushed
*
*/
void add_xor(std::istringstream&, std::vector<gate>& g);

/**
* @brief Pushes nand gate to vector
* @param stringstream with gate description
* @param Vector of gates to be pushed
*
*/
void add_nand(std::istringstream&, std::vector<gate>& g);

/**
* @brief Pushes nor gate to vector
* @param stringstream with gate description
* @param Vector of gates to be pushed
*
*/
void add_nor(std::istringstream&, std::vector<gate>& g);

/**
* @brief Pushes xnor gate to vector
* @param stringstream with gate description
* @param Vector of gates to be pushed
*
*/
void add_xnor(std::istringstream&, std::vector<gate>& g);

/**
* @brief Pushes neg gate to vector
* @param stringstream with gate description
* @param Vector of gates to be pushed
*
*/
void add_not(std::istringstream&, std::vector<gate>& g);

/**
* @brief Links node to gate that filles it
* @param Filled vector of nodes
* @param Filled vector of gates
*
*/
void link_prev(std::vector<node>& n, std::vector<gate>& g);

/**
* @brief Recursive. Executes gate
* @param Filled vector of nodes
* @param Filled vector of gates
* @param Current gate to be executed
*
*/
void exe_rec(std::vector<node>& n, std::vector<gate>& g, int c);
