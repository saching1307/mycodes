#include<iostream>
#include"stack.h"
using namespace std;

int main(){
	stack* elementsToInsert = new stack();
	elementsToInsert->push(10);
	elementsToInsert->push(20);
	cout<<elementsToInsert->top()<<endl;	
	elementsToInsert->push(110);
	cout<<elementsToInsert->pop()<<endl;	
	elementsToInsert->push(102);
	cout<<elementsToInsert->pop()<<endl;	
	cout<<elementsToInsert->pop()<<endl;	
	cout<<elementsToInsert->pop()<<endl;	
}
