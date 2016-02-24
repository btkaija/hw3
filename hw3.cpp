#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "node.h"

using namespace std;

int main(int argv, char **argc)
{
	ifstream input_file;
	ofstream output_file;
	
	input_file.open(argc[1]);

	if(argv > 2)
		cout << "invalid arguments" << endl;
	else if(argv == 1)
	{
		cout << "waiting for input..." << endl;
		string input_val;
		bool is_mult = 0, is_avg = 0, is_add = 0;
			
		Node head = Node();

		do
		{
			cin >> input_val;
			cout << input_val << endl;
			const char *c = input_val.c_str();

			is_add = (strcmp(c, "add") != 0);
			is_mult = (strcmp(c, "multiply") != 0);
			is_avg = (strcmp(c, "average") != 0);
			
				
		}while(is_avg && is_mult &&  is_add);
	}
	else if(input_file)
	{
		cout << "reading file..." << endl;
	}
	else if(!input_file)
	{
		cout << "could not read file specified";
	}

	cout << "Hello World!" << endl;
	return 0;
}
