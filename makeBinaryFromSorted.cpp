#include<iostream>

using namespace std;

class Node
{
	public:
		Node* left;
		Node* right;
		int data;
		Node(int a)
		{
			data = a ;
			left = NULL;
			right = NULL;	
		}
};

class BST
{
	public:	
		Node* root;
		BST()
		{
			root = NULL;
		}
		void insert(int a)
		{
			Node* node = new Node(a);
			if(root == NULL)
			{
				root =  node;
			}
			else
			{
				Node* temp = root;
				Node * temp1;
				while(temp!=NULL)
				{
					if(temp->data > a)
					{
						temp1 = temp;
						temp = temp->left;
					}
					else
					{
						temp1 = temp;
						temp = temp->right;
					}
				}
				if(temp1->data > a)
				{
					temp1->left = node;
				}
				else
				{
					temp1->right = node;
				}
			}
			return;
		}

		void insertRec(Node* parent, int a)
		{
			Node* node = new Node(a);
			if(root == NULL) {
				root = node;
				return;
			}
			else
			{
				if( a <  parent->data)
				{
					if(parent->left == NULL)
					{
						parent->left = node;
						return;
					}
					else
					{
						return insertRec(parent->left, a);
					}
				}	
				else
				{
					if(parent->right == NULL)
                                        {
                                                parent->right = node;
                                                return;
                                        }
                                        else          
                                        {             
                                                return insertRec(parent->right, a);
                                        }
				}
			}
		}

		void print(Node* node)
		{
			if(node == NULL) return;
			cout<<node->data<<" ";
			print(node->left);
			print(node->right);
		}
};

void insertInBST(BST* bst, int start , int end)
{
	if(start > end || end == 0 ) return;
	int mid = (start+end)/2;
	bst->insert(mid);
	insertInBST(bst, start , mid-1);
	insertInBST(bst, mid+1, end); 
}

int main()
{
	BST* bst = new BST();
	insertInBST(bst, 0, 10);
	bst->print(bst->root);
	cout<<endl;
}
