#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "node.h"

using namespace std;

int main(int argv, char **argc)
{
	ifstream input_file;
	istream *input_stream = &cin;

	if(argv > 2)
	{
		cerr << "Invalid number of arguments" << endl;
	}
	else
	{
		//cout << "reading input..." << endl << endl;
		string input_val;
		
		if(argv > 1)
		{	
			input_file.open(argc[1]);
			if(!input_file)
			{
				cerr << "Could not open file." << endl;	
				exit(EXIT_FAILURE);
			}
			
			input_stream = &input_file;
		}

		bool is_mult = 0, is_avg = 0, is_add = 0;
		
		double input_num;		

		Node* head = new Node();
		Node* tail;
		head->set_value(0);
		tail = head;
		do
		{
			//cout << endl;
			
			*input_stream >> input_val;
			
			const char *c = input_val.c_str();
			
			is_add = (strcmp(c, "add") != 0);
			is_mult = (strcmp(c, "multiply") != 0);
			is_avg = (strcmp(c, "average") != 0);
						
			
			if(is_add && is_mult && is_avg)
			{
				input_num = stod(input_val);
				//cout << "value recorded: " << to_string(input_num) << endl;
				
				Node* new_node = new Node();
				new_node->set_value(input_num);
				new_node->set_next(NULL);
				tail->set_next(new_node);
				tail = new_node;
			}	
				
		}while(is_avg && is_mult &&  is_add);
		
		if(input_file) input_file.close();

		//cout << "done inputing values" << endl;
		//cout << "combining values via " << input_val << " operation" << endl;
			
		double result = 0.0;
		if(!is_mult) result = 1;
		double count = 0;		

		while(head->has_next())
		{	
			
			head = head->get_next();
			count ++;
			
			//cout << "computing " << to_string(count) << " value(s)" << endl;	
			//cout << "data: "<< to_string(head->get_value()) << endl;
	
			if(!is_mult) result = head->get_value() * result;
			else result = head->get_value() + result;
			
			//cout << to_string(result) << endl;
		}

		if(!is_avg) result = result/count;
		
		cout << "The result is " << to_string(result) << endl;
	}


	//cout << "completed operations." << endl;
	return 0;
}
