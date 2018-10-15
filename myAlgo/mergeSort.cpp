#include<iostream>

using namespace std;

void print(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;

}
int* merge( int * left, int * right, int n)
{
	int *result;
	result = (int*)malloc(sizeof(int)*n);
	int i=0,l=0,r=0;
	while(i!=n)
	{
		if(left[l] > right[r])
		{
			result[i++] = right[r++];
		}
		else	
		{
			result[i++] = left[l++];
		}
		
		if(l == n/2)
		{
			while(i!=n)
				result[i++] = right[r++];
		}
		if(r==n-n/2)
		{
			while(i!=n)
				result[i++] = left[l++];
		}
	}
	return result;
}

int*  mergeSort(int *a, int n)
{
	if(n==1) return a;
	int * left = mergeSort(a,n/2);
	int * right= mergeSort(a+n/2,n-n/2);
	int *b = merge(left,right,n);
	// TO FREE COPY B TO A and call free on B
	return b;
}

int main()
{
	int n = 10;
	int *a;
	a=(int*)malloc(sizeof(int)*n);	
	for(int i=0;i<n;i++)
		a[i] = rand()%100 * (rand()%2 ? -1 : 1);
	print(a,n);
	int* b =mergeSort(a,n);
	print(b,n);
	free(a);
	free(b);
	return true;
}
