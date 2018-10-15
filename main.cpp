#include<iostream>
#include"linkedlist.h"
using namespace std;

int main(){
	LinkedList* list = new LinkedList();
	list->insert(10);
	list->insert(1021);
	list->insert(102);
	list->insert(101);
	list->printList(list->root);
}
