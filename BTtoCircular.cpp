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


class CircularLinkedList
{	
	public:
		Node *root;
		CircularLinkedList()
		{
			root = NULL;
		}
		void insert(int data)
		{
			Node * node = new Node(data);
			if(root == NULL)
			{
				root = node;
			}
			else
			{
				Node * temp1 = root->left;
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
			Node * node = root;
			cout<<node->data<<" ";
			node = node->right;
			while(node!=root)
			{
				cout<<node->data<<" ";
				node = node->right;
			}
			cout<<endl;
		}
};

Node* rightmostNode(Node* node)
{
	if(node == NULL) return NULL;
	else
        {
                while(node->right!=NULL)
                {
                        node = node->right;
                }
                return node;
        }
}	

Node* leftmostNode(Node* node)
{
	if(node == NULL) return NULL;
	else
	{
		while(node->left!=NULL)
		{
			node = node->left;
		}
		return node;
	}	
}


Node* treeToDoublyList(Node* node)
{
	if(node == NULL) return NULL;
	if(node->left!=NULL)
	{
		treeToDoublyList(node->left);
		Node* rightMost = rightmostNode(node->left);
		rightMost->right = node;
		node->left = rightMost;
	}
	if(node->right!=NULL)
	{
		treeToDoublyList(node->right);
		Node* leftMost = leftmostNode(node->right);
		leftMost->left = node;
		node->right = leftMost;
	}	
	return node;
}

Node* convertBTtoCircular(BST* bst)
{
	Node* root = bst->root;
	// Base case
	if (root == NULL)
		return root;

	// Convert to DLL using treeToDoublyList()
	root = treeToDoublyList(root);
	Node* right = root;
	// treeToDoublyList() returns root node of the converted
	// DLL.  We need pointer to the leftmost node which is
	// head of the constructed DLL, so move to the leftmost node
	while (root->left != NULL)
		root = root->left;


	while (right->right != NULL)
		right = right->right;
	
	right->right = root;
	root->left = right;
	return (root);
}
 

int main()
{
	BST* bst = new BST();
	for(int i=0;i<10;i++)
	{
		int a = (rand()%100) * (rand()%2 == 0 ? -1 : 1);
		bst->insertRec(bst->root, a);
	}
	bst->print(bst->root);
	cout<<endl;
	CircularLinkedList* cl = new CircularLinkedList();
	cl->root = convertBTtoCircular(bst);
	cl->print();
}
