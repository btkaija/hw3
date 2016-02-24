#include <node.h>

//null constructor
Node::Node()
{
}

Node::Node(double val, Node *a_node)
{
	this->data = val;
	this->next = a_node;
}


void Node::append_node(Node *new_node)
{
	new_node->next = this->next;
	this->next = new_node;
}
