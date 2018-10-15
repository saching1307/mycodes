#include<iostream>
#include<vector>
#include<map>
using namespace std;

void printTwoSumUsingHash(int *a,int b,int n)
{
	std::map<int,int> mapDict;
	n = 13;
	for(int i=0;i<n;i++)
	{
		std::map<int,int>::iterator it = mapDict.find(n-a[i]);
		
		if(it!= mapDict.end() && it->second !=0)
		{
			cout<<n-a[i]<< " "<<a[i]<<endl;
			mapDict[n-a[i]] = mapDict[n-a[i]] - 1;
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
		if(a[start]+ a[end] == n)
		{
			cout<<a[start]<< " "<<a[end]<<endl; 
		}
		if(a[start]+ a[end]  >  n)
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
	int a[]= {2,7,4,5,2,3,4,5,6,7,8,9,10};
	int b = 8;	
	printTwoSumUsingHash(a,b,9);

}
