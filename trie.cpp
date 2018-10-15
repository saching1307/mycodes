#include<iostream>

using namespace std;

class Node
{
	public:
		bool isWord;
		char letter;
		Node **child;
		Node(char letter1)
		{
			child = NULL;
			letter = letter1;
			isWord = false;
		}
};

class Trie
{
	public:
		Node **root;
		Trie()
		{
			root = (Node**) malloc(sizeof(Node*) * 26);
			for(int i=0;i<26;i++)
			{
				root[i] = new Node('a' + i);
			}
		}
		void insert(string a)
		{	
			int length = a.length();
			if(length < 1) return;
			Node* current = root[a[0]-'a'];
			for(int i=1;i<length ; i++)
			{
				if(current->child == NULL)
				{
					current->child = (Node**) malloc(sizeof(Node*)*26);
					for(int i=0;i<26;i++)
					{
						current->child[i] = NULL;	
					}
				}
				if(current->child[a[i]-'a']==NULL)
				{
					current->child[a[i]-'a'] = new Node(a[i]);
				} 
				current = current->child[a[i]-'a'];
			}
		}
	
		void print(Node** root)
		{
			if(root == NULL) 
			{
				cout<<endl;
				return;
			}
			for(int i=0;i<26;i++)
			{
				if(root[i]  != NULL)
				{
					cout<<root[i]->letter<<" ";
					print(root[i]->child);
				}
			}
		}

		bool search(string a)
		{
			int length = a.length();
			if(length < 1) return true;
			Node* current = root[a[0] - 'a'];
			for(int i=1;i<length ; i++)
			{
				if(current->child == NULL)
				{
					return false;
				}
				if(current->child[a[i]-'a']==NULL)	return false;
				current = current->child[a[i]-'a'];
			}
			return true;
		}
};

int main()
{
	Trie* t1 = new Trie();
	t1->insert("sachin");
	t1->insert("sach");
	t1->insert("ach");
	cout<<t1->search("sachin");
}
