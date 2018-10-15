
#include<iostream>
#include<math.h>
using namespace std;


void printZigZag(int *a, int n)
{
	bool right = false;
	int i=0;
	int printInThisLevel = 1;
	int start = 0;
	int end=0;
	while(i!=n)
	{
		while(start <= end)
		{
			if(right)
			{
				cout<<a[start]<< " ";
				start++;
			}
			else
			{
				cout<<a[end]<< " ";
				end--;
			}
			i++;
		}
		cout<<endl;
		if(!right)
			start = end + printInThisLevel + 1;
		else 
			start = end + 1;
		printInThisLevel *=2;
		end = start + printInThisLevel - 1; 
		right^=1;
	}	
}

int main()
{
	int n= 63;
	int *a;
	a = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		a[i] = i+1;
	printZigZag(a,n);
}
