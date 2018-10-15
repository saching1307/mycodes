#include<iostream>

using namespace std;

int diff = 0;
void printMissing(int *a,int low, int max, int start , int end)
{
	if(start >  end)
		return;	

	if ((a[end] - a[start] + 1) - (end - start) == 0) {
		return;
	}

	if (start + 1 == end) {
		for (int i = a[start] + 1; i < a[end]; i++) {
			cout<<i<< " "<<endl;
		}
		return;
	}
	int mid = (start + end)/2;

	printMissing(a, low, max , start, mid);
	printMissing(a,  low , max, mid , end);

}

int main()
{
	int *i;
	int n = 6;
	i = (int*)malloc(sizeof(int)*n);
	i[0] = 1;
	i[1] = 2;
	i[2] = 4;
	i[3] = 5;
	i[4] = 6;
	i[5] = 9;
	printMissing(i,1,9,0,6);
}
