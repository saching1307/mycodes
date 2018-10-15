#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
		node(int a)
		{
			data = a;
			left = NULL;
			right = NULL;
		}

};

class BST{

	public:
		node* root;
		BST()
		{
			root = NULL;
		}
		void insert(node* root1, int a)
		{
			node* newNode = new node(a);
			if(root == NULL){	
				root = newNode;
				return;
			}
			if(root1->data > a){
				if(root1->right == NULL){
					root1->right = newNode;
				}
				else { insert(root1->right,a);
				}
			} else {
				if(root1->left == NULL){
					root1->left = newNode;
				}
				else { insert(root1->left,a);}
			}
			return ;
		}
		void printBST(node* root){
			if(root == NULL) return;
			printBST(root->left);
			cout<<root->data<< " ";
			printBST(root->right);
		}
};


bool checkBSTHelper(node* a){
		bool leftCheck = true;
		bool rightCheck = true;
		if(a!=NULL){
			if(a->left!=NULL) { if (a->left->data > a->data) return false;} else { leftCheck = checkBSTHelper(a->left);}	
			if(a->right!=NULL) { if (a->right->data < a->data) return false;} else { rightCheck = checkBSTHelper(a->right);}	
		}
		return leftCheck && rightCheck;
}
bool chestBST(BST* a){
	return checkBSTHelper(a->root);	
}

int main(){

	BST* b = new BST();
	b->insert(b->root,10);
	b->insert(b->root,100);
	b->insert(b->root,-10);
	b->insert(b->root,0);
	b->printBST(b->root);
	cout<<chestBST(b);
}
