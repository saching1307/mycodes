#include<iostream>
#include<vector>
#include<map>
using namespace std;

void printTwoSumUsingHash(int *a,int b,int n)
{
	std::map<int,int> mapDict;
	for(int i=0;i<n;i++)
	{
		std::map<int,int>::iterator it = mapDict.find(b-a[i]);
		
		if(it!= mapDict.end() && it->second !=0)
		{
			cout<<b-a[i]<< " "<<a[i]<< " "<<b<<endl;
			mapDict[b-a[i]] = mapDict[b-a[i]] - 1;
		}
		else
		{
			mapDict[a[i]] = 1;
		}
	}
}

void printTwoSum(int* a, int b, int n)
{
	int start=0;
	int end = n-1;
	while(start < end)
	{
		if(a[start]+ a[end] == b)
		{
			cout<<a[start]<< " "<<a[end]<< " "<<b<<endl; 
		}
		if(a[start]+ a[end]  >  b)
		{
			end--;
		}
		else
		{
			start++;
		}
	}
}


int main()
{
	int a[]= {-1,0,1,2,2,3};
	for(int i=0;i<6;i++)
		printTwoSum(a,-a[i],6);
}
