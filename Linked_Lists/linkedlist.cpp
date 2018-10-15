#include"linkedlist.h"

node::node(int newValue)
{
	data = newValue;
}

LinkedList::LinkedList()	
{
	this->root = NULL;	
}

void LinkedList::insert(int dataToInsert)	
{	
	node* newNode = new node(dataToInsert);
	newNode->next = root;
	root = newNode;
}

void LinkedList::printList(node* NodeToPrint){
	if(NodeToPrint == NULL) return;	
	cout<<NodeToPrint->data<<" " ;
	printList(NodeToPrint->next);
}

void LinkedList::deleteNode(node* NodeToDelete){
		if( NodeToDelete == NULL) return;	
		if(root == NodeToDelete){
			node* temp = NodeToDelete->next;
			free(NodeToDelete);
			root = temp;
		}
		else{
			node* temp = root;
			while(temp && temp->next!=NodeToDelete){
				temp = temp->next;
			}
			if(temp!=NULL)
			{
				node* temp2 = temp->next->next;
				free(temp->next);
				temp->next->next = temp2;
			}
		}	
}
