#include "node.h"

Node::Node()
{
	next = NULL;
}

Node::Node(Node *a_node)
{
	data = a_node->data;
	next = a_node->next;
}

void Node::set_next(Node *new_node)
{
	if(new_node == NULL)
		next = NULL;
	else
		next = new_node;
}

double Node::get_value()
{
	return data;
}

void Node::set_value(double d)
{
	data = d;
}

Node*  Node::get_next()
{
	return next;
}

bool Node::has_next()
{
	if(next == NULL)
		return false;
	else
		return true;
}
