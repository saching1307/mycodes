#include<iostream>

using namespace std;

class UF
{
	public:
		UF(int n);
		bool connected(int n, int m);
		bool find(int n);
		bool connect(int n, int m);
};


class QuickFindUF
{	
	int *id;
	int n;
	public:
		QuickFindUF(int N)
		{
			n = N;
			id = (int*) malloc(sizeof(int) * n);
			for(int i=0;i<n;i++)
			{
				id[i] = i;
			}
		}
		~QuickFindUF()
		{
			free(id);
		}
		int root(int m)
		{	
			while(1)
			{
				if(m == id[m])
				{		
					return m;
				}
				m = id[m];
			}
		}

		void connect(int N,int m)
		{
			if(N < n && m < n)
			{
				if(!connected(N,m))
				{
					int rootN = root(m);
					id[rootN] = id[n];
				}
			}
		}

		bool connected(int N, int m)
		{
			if(N < n && m < n)
			{
				if(root(N) == root(m))
					return true;
			}
			return false;
		}
		void print()
		{
			for(int i=0;i<n;i++)
			{
				cout<<id[i]<<" ";
			}
		}
};

int main()
{
	int n;
	cin>>n;
	QuickFindUF *qf= new QuickFindUF(n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a;
		cin>>b;
		qf->connect(a,b);
	}	

	qf->print();
	cout<< endl;
	free(qf);


	return true;
}
