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
			print(node->left);
			cout<<node->data<<" ";
			print(node->right);
		}
};

int maxHeight(Node * root)
{
	if(root == NULL) return 0;
	return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}

bool isBSTBalanced(BST *b)
{
	if(b== NULL || b->root == NULL) return true;
	Node * root = b->root;
	int leftHeight = maxHeight(root->left) + 1;
	int rightHeight = maxHeight(root->right) + 1;
	if(abs(leftHeight - rightHeight) > 1)
	{
		cout<<leftHeight<<" "<<rightHeight<<" "<<endl;
		return false;
	}	
	else
	{
		cout<<leftHeight<<" "<<rightHeight<<" "<<endl;
		return true;
	}
}

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
	for(int j = 0 ; j< 0 ; j++)
	{
		BST* bst = new BST();
		for(int i=0;i<10;i++)
		{
			int a = (rand()%1000) * (rand()%4 == 0 ? -1 : 1);
			cout<<a<< " ";
			bst->insertRec(bst->root, a);
		}
		cout<<endl;
		bst->print(bst->root);
		cout<<endl;
		cout<<isBSTBalanced(bst)<<endl;
	}
	BST* bst = new BST();
	insertInBST(bst, 0, 100);
	cout<<isBSTBalanced(bst);	
	
}
