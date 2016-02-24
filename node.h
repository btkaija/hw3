#include <iostream>

using namespace std;

class Node
{
private:
	double data;
	Node *next;

public:
	Node();
	Node(Node *a_node);
	void set_next(Node *new_node);
	Node* get_next();
	void set_value(double d);
	double get_value();
	bool has_next();
};
