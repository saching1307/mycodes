#include<iostream>
#include <queue>  

using namespace std;

class point
{
	public:
		int x,y;
		point(int a, int b ): x(a),y(b) { }
};

void printMatrixDiagonal(int **x, int n)
{
	for (int slice = 0; slice < 2 * n - 1; ++slice) {
		printf("Slice %d: ", slice);
		int z = slice < n ? 0 : slice - n + 1;
		for (int j = z; j <= slice - z; ++j) {
			printf("%d ", x[j][slice - j]);
		}
		printf("\n");
	}
}

void myprintMatrixDiagonal(int **a, int n)
{
	int isPrinted[n][n];
	for(int i=0;i<n;i++)
	{   
		for(int j=0;j<n;j++)
		{   
			isPrinted[i][j] = -1;
		}   
	}   

	int printed = 0;
	queue<point*> visitedNodes;
	point *p = new point(0,0);
	visitedNodes.push(p);
	while(!visitedNodes.empty())
	{
		p = visitedNodes.front();
		visitedNodes.pop();
		if(isPrinted[p->x][p->y]==1)
			continue;
		cout<<a[p->x][p->y]<< " ";
		isPrinted[p->x][p->y] = 1;
		if(p->y+1 < n)
		{
			point* down = new point(p->x,p->y+1);
			visitedNodes.push(down);
		}
		if(p->x+1 < n)
		{
			point* right = new point(p->x+1,p->y);
			visitedNodes.push(right);
		}
	}
}

int main()
{
	int n=4;
	int **a;
	a=(int**)malloc(sizeof(int*)*n);

	for(int i=0;i<n;i++)
	{
		a[i]=(int*)malloc(sizeof(int)*n);
		for(int j=0;j<n;j++)
		{
			a[i][j] = i*n + j+1;
		}
	}
	printMatrixDiagonal(a,n);
}
