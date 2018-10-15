#include"linkedlist.h"

class stack{
	public:
		LinkedList* list;
		stack();
		void push(int value);
		int pop();
		int top();
};
