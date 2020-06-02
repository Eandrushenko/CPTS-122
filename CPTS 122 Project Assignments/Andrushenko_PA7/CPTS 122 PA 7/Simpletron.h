/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall  2016; Lab Section 04

* Programming Assignment: PA6

* Date: October 26th, 2016

* Description: This program converts english writing to morse code.

* History: 11/4/2016 Created the readfile, fetch, decode, and the outline for execute.
11/10/2016 finished the project by finishing the execute functions and the run function.

*******************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

#pragma once

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::istream;
using std::ostream;
using std::string;

class Simpletron
{
	public:
		//Constructor
		Simpletron();

		//Destructor
		~Simpletron();

		//Getters
		int getOpcode();
		int getOperand();
		int getCounter();
		int getAccumulator();

		//Setters
		void setOpcode(int newOpcode);
		void setOperand(int newOperand);
		void setCounter(int newCounter);
		void setAccumulator(int newAccumulator);

		//Member Functions
		void readfile();
		int fetch();
		void decode(int command);
		int execute();
		void display(int number);

		//execute() functions
		void read();
		void write();
		void load();
		void store();
		void add();
		void subtract();
		void divide();
		void multiply();
		void branch();
		void branch_zero();
		void branch_negative();
		int halt();
		void modulus();
		void exponential();


	private:
		int mMemory[1000];
		int mOpcode;
		int mOperand;
		int mCounter;
		int mAccumulator;
};

//Nonmember Functions
void run();



