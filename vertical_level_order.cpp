#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <map>

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

		void printAllPath(Node* node, string prefix)
		{
			if(node == NULL)
			{
				return;
			}


			string newAddition = to_string(node->data) + " ";
			int lengthOfAddition = newAddition.length();
			prefix = prefix + newAddition;
			printAllPath(node->left, prefix);
			printAllPath(node->right, prefix);
			if(node->left == NULL && node->right == NULL)
			{
				cout<<"printint Here"<<endl;
				cout<<prefix<<endl;
			}
			prefix = prefix.substr(0, prefix.length()-lengthOfAddition);


		}

		void printPathSum(Node* node, int sum)
                {
                        if(node == NULL)
                        {
                                return;
                        }

			if(node->left == NULL && node->right == NULL)
                        {
                                cout<<"printint Here"<<endl;
                                cout<<sum + node->data<<endl;
				return;
                        }

                        sum += node->data;
                        printPathSum(node->left, sum);
                        printPathSum(node->right, sum);
                }

		int sumTree(Node* node)
		{
			int sum = 0;
			if(node == NULL) return sum;
			sum+=node->data;
			sum+=sumTree(node->left);
			sum+=sumTree(node->right);
			cout<<sum<<" " <<endl;
			return sum;
		}

		void print(Node* node)
		{
			if(node == NULL) return;
			print(node->left);
			cout<<node->data<<" ";
			print(node->right);
		}

		void printSumOfEachRow(Node* node)
		{

			int row = 0;
			if(node == NULL)
			{
				cout<<"Sum of row ::"<<row<<" is:: "<<0<<endl;
			}

			queue<Node*> *nodeQueue = new queue<Node*>();
			nodeQueue->push(node);
			nodeQueue->push(NULL);

			int sum = 0;
			while(!nodeQueue->empty())
			{
				Node* currentNode = nodeQueue->front();

				nodeQueue->pop();
				if(currentNode == NULL)
					return;
				if(currentNode->left)
				{
					nodeQueue->push(currentNode->left);
				}

				if(currentNode->right)
				{
					nodeQueue->push(currentNode->right);
				}

				sum+= currentNode->data;

				if(nodeQueue->front() == NULL)
				{
					cout<<"Sum of row ::"<<row<<" is:: "<<sum<<endl;
					row++;
					sum = 0;
					nodeQueue->pop();
					nodeQueue->push(NULL);
				}

			}
			return;
		}

		stack<Node*> s1;
		Node* inorderNonRec()
		{
			 static Node* current = root;

			if(s1.empty() && current == NULL) return NULL;

			while(current !=NULL)
			{
				s1.push(current);
				current = current->left;
			}

			current =s1.top();
			Node* node = current;
			s1.pop();
			current = current->right;
			return node;
		}
};

void printVerticalLevel(Node* root, int distance, map <int, vector<int> > &output){
		if(root == NULL){
			return;
		}

		output[distance].push_back(root->data);
		printVerticalLevel(root->left, distance-1, output);
		printVerticalLevel(root->right, distance+1, output);
		return;
}


int main()
{
	int n = 5;
	BST* bst = new BST();

	bst->insertRec(bst->root, 2);
	bst->insertRec(bst->root, 1);
	bst->insertRec(bst->root, 5);
	bst->insertRec(bst->root, 3);
	bst->insertRec(bst->root, 6);
	map <int, vector<int> > output;
	cout<<endl;

	printVerticalLevel(bst->root, 0, output);
	map< int,vector<int> > :: iterator it;
	for (it=output.begin(); it!=output.end(); it++)
	{
				vector<int> print_set = it->second;
				for(int i=0 ; i<print_set.size();i++){
					cout<<print_set[i]<< " ";
					}
				cout<<endl;
		}
}
