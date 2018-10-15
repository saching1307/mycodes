#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(int a)
        {
            data = a;
            next = NULL;
        }
};

class LinkedList
{
      public:
          Node* root;
          LinkedList()
          {
              root = NULL;
          }
          
          void insert(int a)
          {
              Node* node = new Node(a);
              node->next = root;
              root = node;
          }
          
          void print()
          {
              Node* temp = root;
              while(temp!=NULL)
              {
                  cout<<temp->data<<" ";
                  temp = temp->next;
              }
              cout<<endl;
          }
};

Node* findKthToLast(LinkedList* l1, int k)
{
	Node* fast = l1->root;
	Node* slow = l1->root;
	while(k!=0)
	{
		if(fast == NULL) {return NULL;}
		fast = fast->next;
		k--;	
	}
	while(fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
	
	
}

void reverseLinkedListIterative(LinkedList *l1)
{
	Node* temp = l1->root;
	Node* temp1 = NULL;
	while(temp->next!=NULL)
	{
		
	}
}

void reverseRecursion2(LinkedList * l1, Node *cur, Node* prev)
{
	if(cur == NULL) return;
	if(cur->next == NULL)
	{
		l1->root = cur;
	}
	
	Node* temp = cur->next;
	cur->next = prev;
	return reverseRecursion2(l1, temp , cur);
}

void deleteNode(LinkedList* l1, Node * nodeToDelete)
{
	if(nodeToDelete == NULL) return;
	Node* temp = nodeToDelete->next;
	if(temp == NULL)
	{
		nodeToDelete = NULL;
		return;
	}
	else
	{
		Node* temp1 = nodeToDelete->next->next;
		nodeToDelete->data = temp->data;
		delete(temp);
		nodeToDelete->next = temp1;
	}

}

int main()
{
    LinkedList* linkedList = new LinkedList();
    for(int i = 0 ;i< 5;i++)
    {
        linkedList->insert(rand()%100);
    }
    linkedList->print();
    reverseRecursion(linkedList, linkedList->root);
    linkedList->print();
}
