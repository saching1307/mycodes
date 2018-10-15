#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(int newValue);
};

class LinkedList{
	public:
		node* root;
		LinkedList();
		void insert(int dataToInsert);
		void printList(node* NodeToPrint);
		void deleteNode(node* nodeToDelete);
};
