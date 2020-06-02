/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall  2016; Lab Section 04

* Programming Assignment: PA6

* Date: October 26th, 2016

* Description: This program converts english writing to morse code.

* History: 11/4/2016 Created the readfile, fetch, decode, and the outline for execute.
11/10/2016 finished the project by finishing the execute functions and the run function.

*******************************************************************************************/

#include "Simpletron.h"

/*************************************************************
* Function: Simpletron()
* Date Created: 11/04/2016
* Date Last Modified: 11/04/2016
* Description: The constructor for Simpletron
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
Simpletron::Simpletron()
{
	mOpcode = 0;
	mOperand = 0;
	mCounter = 0;
	mAccumulator = 0;
	int i = 0;
	while (i < 1000)
	{
		mMemory[i] = 0;
		i += 1;
	}
}

/*************************************************************
* Function: ~Simpletron()
* Date Created: 11/04/2016
* Date Last Modified: 11/04/2016
* Description: The destructor for Simpletron
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
Simpletron::~Simpletron()
{

}

/*************************************************************
* Function: readfile()
* Date Created: 11/04/2016
* Date Last Modified: 11/04/2016
* Description: reads from a file and populates the memory array respectively
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::readfile()
{
	string sml = " ";
	cout << "Enter a file to read from: ";
	cin >> sml;

	char i[10];
	int j = 0, k = 0;
	ifstream input;

	input.open(sml);

	while (!(input.eof()))
	{
		input.getline(i, 10, '\n');
		i[0] = '0';
		j = atoi(i);
		mMemory[k] = j;
		k += 1;
	}

	input.close();
}


/*************************************************************
* Function: fetch()
* Date Created: 11/04/2016
* Date Last Modified: 11/04/2016
* Description: gets the nformation from an index within the memory array
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
int Simpletron::fetch()
{
	return mMemory[mCounter++];
}

/*************************************************************
* Function: decode()
* Date Created: 11/04/2016
* Date Last Modified: 11/04/2016
* Description: decodes the command into the opcode and operand
* Input parameters: command
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::decode(int command)
{
	mOpcode = command / 1000;
	mOperand = command % 1000;
}

/*************************************************************
* Function: execute()
* Date Created: 11/04/2016
* Date Last Modified: 11/09/2016
* Description: runs the opcode and operand commands
* Input parameters: N/A
* Returns: result
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
int Simpletron::execute()
{
	int result = 0;
	if (mOpcode == 10)//read
	{
		read();
	}
	else if (mOpcode == 11)//write
	{
		write();
	}
	else if (mOpcode == 20)//load
	{
		load();
	}
	else if (mOpcode == 21)//store
	{
		store();
	}
	else if (mOpcode == 30)//add
	{
		add();
	}
	else if (mOpcode == 31)//subtract
	{
		subtract();
	}
	else if (mOpcode == 32)//divide
	{
		divide();
	}
	else if (mOpcode == 33)//multiply
	{
		multiply();
	}
	else if (mOpcode == 40)//branch
	{
		branch();
	}
	else if (mOpcode == 41)//branch negative
	{
		branch_negative();
	}
	else if (mOpcode == 42)//branch zero
	{
		branch_zero();
	}
	else if (mOpcode == 43)//halt
	{
		result = halt();
	}
	else if (mOpcode == 35)//modulus
	{
		modulus();
	}
	else if (mOpcode == 34)//exponential
	{
		exponential();
	}
	return result;
}

/*************************************************************
* Function: read()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: reads an index in the array
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::read()
{
	cout << ">> ";
	cin >> mMemory[mOperand];
}

/*************************************************************
* Function: write()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: displays an index in an array
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::write()
{
	cout << mMemory[mOperand] << endl;
}

/*************************************************************
* Function: load()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: allows you to set the Accumulator
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::load()
{
	cout << ">> ";
	cin >> mAccumulator;
}

/*************************************************************
* Function: store()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: allows you to store the accumulator in an index in the array
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::store()
{
	mMemory[mOperand] = mAccumulator;
}

/*************************************************************
* Function: add()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: adds to the accumulator
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::add()
{
	mAccumulator += mMemory[mOperand];
}

/*************************************************************
* Function: subtract()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: subtracts from the accumulator
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::subtract()
{
	mAccumulator -= mMemory[mOperand];
}

/*************************************************************
* Function: divide()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: divides the accumulator
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::divide()
{
	mAccumulator /= mMemory[mOperand];
}

/*************************************************************
* Function: multiply()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: multiplies the accumulator
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::multiply()
{
	mAccumulator *= mMemory[mOperand];
}

/*************************************************************
* Function: branch()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: branches to a spot in memory
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::branch()
{
	mCounter = mOperand;
}

/*************************************************************
* Function: branch_negative()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: branches to a spot in memory if the accumulator is negative
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::branch_negative()
{
	if (mAccumulator < 0)
	{
		mCounter = mOperand;
	}
}

/*************************************************************
* Function: branch_zero()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: branches to a spot in memory if the accumulator is equal to zero
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::branch_zero()
{
	if (mAccumulator == 0)
	{
		mCounter = mOperand;
	}
}

/*************************************************************
* Function: halt()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: exits the program
* Input parameters: N/A
* Returns: 1
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
int Simpletron::halt()
{
	return 1;
}

/*************************************************************
* Function: modulus()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: performs modulus on the accumulator
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::modulus()
{
	mAccumulator = mAccumulator % mMemory[mOperand];
}

/*************************************************************
* Function: exponential()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: multiplies the accumulator to a certain power
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::exponential()
{
	mAccumulator = pow(mAccumulator, mMemory[mOperand]);
}

/*************************************************************
* Function: display()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: displays the first 100 places in memory and other operations
* Input parameters: number
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void Simpletron::display(int number)
{
	printf("REGISTERS:\n");
	printf("accumulator\t\t +%06d\n", mAccumulator);
	printf("instructionCounter\t  %06d\n", mCounter);
	printf("instructionRegister\t +%06d\n", number);
	printf("operationCode\t\t  %06d\n", mOpcode);
	printf("operand\t\t\t  %06d\n\n", mOperand);
	printf("MEMORY:\n");
	printf("      0       1       2       3       4       5       6       7       8       9\n");
	printf("0  +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d\n", mMemory[0], mMemory[1], mMemory[2], mMemory[3], mMemory[4], mMemory[5], mMemory[6], mMemory[7], mMemory[8], mMemory[9]);
	printf("10 +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d\n", mMemory[10], mMemory[11], mMemory[12], mMemory[13], mMemory[14], mMemory[15], mMemory[16], mMemory[17], mMemory[18], mMemory[19]);
	printf("20 +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d\n", mMemory[20], mMemory[21], mMemory[22], mMemory[23], mMemory[24], mMemory[25], mMemory[26], mMemory[27], mMemory[28], mMemory[29]);
	printf("30 +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d\n", mMemory[30], mMemory[31], mMemory[32], mMemory[33], mMemory[34], mMemory[35], mMemory[36], mMemory[37], mMemory[38], mMemory[39]);
	printf("40 +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d\n", mMemory[40], mMemory[41], mMemory[42], mMemory[43], mMemory[44], mMemory[45], mMemory[46], mMemory[47], mMemory[48], mMemory[49]);
	printf("50 +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d\n", mMemory[50], mMemory[51], mMemory[52], mMemory[53], mMemory[54], mMemory[55], mMemory[56], mMemory[57], mMemory[58], mMemory[59]);
	printf("60 +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d\n", mMemory[60], mMemory[61], mMemory[62], mMemory[63], mMemory[64], mMemory[65], mMemory[66], mMemory[67], mMemory[68], mMemory[69]);
	printf("70 +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d\n", mMemory[70], mMemory[71], mMemory[72], mMemory[73], mMemory[74], mMemory[75], mMemory[76], mMemory[77], mMemory[78], mMemory[79]);
	printf("80 +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d\n", mMemory[80], mMemory[81], mMemory[82], mMemory[83], mMemory[84], mMemory[85], mMemory[86], mMemory[87], mMemory[88], mMemory[89]);
	printf("90 +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d +%06d\n\n", mMemory[90], mMemory[91], mMemory[92], mMemory[93], mMemory[94], mMemory[95], mMemory[96], mMemory[97], mMemory[98], mMemory[99]);
}

/*************************************************************
* Function: run()
* Date Created: 11/09/2016
* Date Last Modified: 11/09/2016
* Description: wraps the app into one function
* Input parameters: N/A
* Returns: N/A
* Preconditions: Simpletron object must be created
* Postconditions: N/A
*************************************************************/
void run()
{
	Simpletron s;
	int number = 0, stopper = 0;
	s.display(number);
	s.readfile();
	system("cls");

	while (stopper == 0)
	{
		s.display(number);
		number = s.fetch();
		s.decode(number);
		stopper = s.execute();
		system("pause");
		system("cls");

	}
}