#include <iostream>

using namespace std;

class Node
{
public:
	double data;
	Node *next;
	Node();
	Node(double val, Node *a_node = NULL);
	void append_node(Node *new_node);
};
