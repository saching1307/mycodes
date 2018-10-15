#nclude<iostream>
#include<math.h>
#include<queue>

using namespace std;

class node
{
	public:
		int data;
		class node* left;
		class node* right;
		node(int a)
		{
			data = a;
			left = NULL;
			right = NULL;
		}
};

bool isBST(BST *a)
{
	if(a==NULL)
		return true;
	bool isLeftBST = true;
	bool isRightBST = true; 
	if(a->left && a->left->data < a->data)
		isLeftBST = isBST(a->left);
	else if(a->left->data > a->data)
		isLeftBST = false;
	if(a->right && a->right->data > a->data)
		isRightBST = isBST(a->right);
	else if(a->right->data < a->data)
		isRightBST = false;
	return isRightBST && isLeftBST;

}
class BST
{
	private:
		class node* root;

	public:
		class node*  getRoot()
		{
			return root;
		}
		BST() 
		{
			root = NULL;
		}
		void insert(int a)
		{
			if(root == NULL)
			{
				root = new node(a);	
				return;
			}
			else
			{
				class node* head = root;
				while(1)
				{
					if(head->data > a)
					{
						if(head->left == NULL)
						{
							class node* temp = new node(a);
							head->left = temp;
							break;
						}	
						else 
							head = head->left;
					}
					else 
					{
						if(head->right == NULL)
						{
							class node* temp = new node(a);
							head->right = temp;
							break;
						}	
						else 
							head = head->right;
					}		
				}

			}
		}
		void printInOrderBST(class node* root)
		{
			if(root == NULL) return;
			printInOrderBST(root->left);
			cout<<root->data<< " "<<endl;
			printInOrderBST(root->right);
		}

		bool isBalanced(class node* root)
		{
			if(root == NULL) return true;
			int hl = heightOfBST(root->left);
			int rl = heightOfBST(root->right);
			if(abs(hl-rl)<1)
			{
				return isBalanced(root->left) && isBalanced(root->right);
			}
			else
				return false;
		}

		int heightOfBST(class node* root)
		{
			if(root == NULL) return 0;
			int hl = 0, rl = 0;
			if(root->left)
				hl = heightOfBST(root->left);
			if(root->right)
				rl = heightOfBST(root->right);
			
			return max(hl,rl) + 1;
		}

		void printBST(class node* root)
		{
			queue<node*> q;
			if(root!=NULL)
				q.push(root);
			while(!q.empty())
			{
				node * top =q.front();
				q.pop();
				if(top->left!=NULL)
					q.push(top->left);
				if(top->right!=NULL)
					q.push(top->right);
				cout<<top->data<< " ";
			}	
			cout<<endl;
		}
};

bool checkForBST(class node*a, int minimumValue)
{
	if(a->left!=NULL)
	{
		if(minimumValue <  a->left->data)
		{
			return false;
		} 
		if(checkForBST(a->left,a->left->data)==false)
			return false;
	}

	if(a->right!=NULL)
	{
		if(minimumValue > a->right->data)
		{
			return false;
		}
		if(checkForBST(a->right,a->right->data)==false)
			return false;
	}
	return true;
}

bool isItBSTree(class BST*a)
{
	bool t = checkForBST(a->getRoot(), a->getRoot()->data);
	cout<< true<< " " << (bool)t<<endl;
	return t;
}

bool presentInSubtree(node* root, int a)
{
	if(root == NULL) return false;
	if(root->data == a) return true;
	if(!presentInSubtree(root->left,a))
		return presentInSubtree(root->right,a);
	else
		return true;
}

node* LCS(node* root, int a, int b)
{

	if(root->left!=NULL && presentInSubtree(root->left,a) == presentInSubtree(root->left,b) && presentInSubtree(root->left,b) == true)
		return LCS(root->left,a,b);
	else if(root->right!=NULL && presentInSubtree(root->right,a) == presentInSubtree(root->right,b) && presentInSubtree(root->right,b) == true)
		return LCS(root->right,a,b);
	return root;
}

int main()
{
		class BST* a = new BST();
		a->insert(1004);
		a->insert(-100);	
		a->insert(-2100);
		a->insert(1020);
		a->insert(100);
		a->insert(1005);
		a->insert(1200);
		a->printBST(a->getRoot());
		cout<<endl;
		cout<<a->heightOfBST(a->getRoot())<<endl;		
		cout<<a->isBalanced(a->getRoot())<<endl;		
}
