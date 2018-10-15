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
					if(rand()%2 == 0)
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
				if(rand()%2 == 0)
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
			print(node->left);
			cout<<node->data<<" ";
			print(node->right);
		}
};

bool checkBSTHelper(Node* root)
{
	if(root == NULL) return true;
	bool left = true;
	bool right = true;
	if(root->left != NULL)
	{
		if(root->left->data > root->data)
		{
			return false;
		}
		left =  checkBSTHelper(root->left);
	}
	 if(root->right != NULL)
        {
                if(root->right->data < root->data)
                {
                        return false;
                }
		right = checkBSTHelper(root->right);
        }
	return left && right;
}

int main()
{
	BST* bst = new BST();
	for(int i=0;i<10;i++)
	{
		int a = (rand()%100) * (rand()%2 == 0 ? -1 : 1);
		cout<<a<< " ";
		bst->insertRec(bst->root,a);
	}
	cout<<endl;
	bst->print(bst->root);
	cout<<endl;
	cout<<checkBSTHelper(bst->root);
	cout<<endl;
}
