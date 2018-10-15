#include<iostream>

using namespace std;

void print(int* a, int n)
{
        for(int i=0;i<n;i++) cout<<a[i]<< " ";
        cout<<endl;
}


int moveToEnd(int *a, int start, int end, int order)
{
	while(start < end && a[start]!=order)
	{
		start++;
	}

	while(start < end && a[end]==order)
	{
		end--;
	}
	
	if(start < end)
	{
		int temp = a[end];
		a[end] = a[start];
		a[start] = temp;
		return moveToEnd(a,start+1,end-1,order);
	}
	return end;
}

void swap(int *a, int *b)
{
	int x;
	x = *a;
	*a = *b;
	*b = x;
}

void dutchSort(int *Arr, int n)
{
	int low = 0;
	int mid = 0;
	int high = n-1;

	while( mid <= high)
	{
		switch(Arr[mid])
		{
			case 0:
				swap(&Arr[low],&Arr[mid]);
				low++;
				mid++;
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(&Arr[mid],&Arr[high]);
				high --;
				break;
		}
	} 
}

int main()
{
	for(int n=10;n<30;n++)
	{
		int a[n];
		for(int i=0;i<n;i++)
			a[i] = rand()%3;
		print(a,n);
		dutchSort(a,n);
		print(a,n);
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
	}
}
