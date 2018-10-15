#include<iostream>

using namespace std;

template<class T>
class Node
{
	public:	
		Node* left;
		Node* right;
		T data;
		Node(T a)
		{
			left = this;
			right = this;
			data = a;
		}
};

class CircularLinkedList
{	
	public:
		Node<int> *root;
		CircularLinkedList()
		{
			root = NULL;
		}
		void insert(int data)
		{
			Node<int> * node = new Node<int>(data);
			if(root == NULL)
			{
				root = node;
			}
			else
			{
				Node<int> * temp1 = root->left;
				node->right = root;
				node->left = temp1;
				temp1->right = node;
				root->left = node;
				root = node;
			}
		}
	
		void print()
		{
			if(root==NULL) return;
			Node<int> * node = root;
			cout<<node->data<<" ";
			node = node->right;
			while(node!=root)
			{
				cout<<node->data<<" ";
				node = node->right;
			}
		}
};

int main()
{
	CircularLinkedList* cl = new CircularLinkedList();
	cl->insert(10);
	cl->insert(110);
	cl->insert(120);
	cl->insert(1201);
	cl->insert(1209);
	cout<<cl->root->right<< " "<<cl->root->right->right->left<<endl;
	cl->print();
}

