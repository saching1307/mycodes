#include"stack.h"

stack::stack()
{
	list = new LinkedList();
}

void stack::push(int value)
{
	list->insert(value);
}

int stack::pop()
{
	int topValue = list->root->data;
	list->deleteNode(list->root);
	return topValue;
}

int stack::top()
{
	int topValue = list->root->data;
	return topValue;	
}
