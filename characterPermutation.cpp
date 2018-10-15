#include<iostream>

using namespace std;


int countOfANumber(int *a, int start, int end)
{
	if(start >= end) 
		return 0;

	int count =  countOfANumber(a, start + 1 ,end);
	if(start + 1 < end && a[start] * 10 + a[start+1]  <= 26)
	{
		count++;
		count += countOfANumber(a, start + 2, end);
	}
	cout<<"start:: "<<a[start]<<" end::"<<a[end-1]<<" "<<start<<" " <<end-1<<" count:: "<<count<<endl;
	return count;       
}

int countOfANumber(int *a, int n)
{
	int k  = countOfANumber(a,0,n) + 1;
	return k;
}

int main()
{
	int a[2]= {1,2};
	cout<<countOfANumber(a,2)<<endl;
	int a1[3]= {1,2,2};
	cout<<countOfANumber(a1,3)<<endl;
	int a2[4]= {1,2,2,2};
	cout<<countOfANumber(a2,4)<<endl;
	int a3[5]= {1,2,3,1,5};
	cout<<countOfANumber(a3,5)<<endl;
}
