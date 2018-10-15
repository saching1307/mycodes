#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Heap
{
	public:
		vector<int> a;
		Heap()
		{
		}		
		
		void insert(int data)
		{
			if(a.size() == 0)
			{
				a.push_back(data);
			}	
			else
			{
				a.push_back(data);
				int currentLevel = a.size() - 1;
				while(currentLevel > 0 && a[currentLevel] > a[(currentLevel-1)/2])
				{
					int temp = a[currentLevel];
					a[currentLevel] = a[(currentLevel-1)/2];
					a[(currentLevel-1)/2] = temp;
					currentLevel= (currentLevel-1)/2;
				}	
			}
		}
		
		int maxElement()
		{
			if(a.size() == 0) return -1;
			else
				return a[0];
		}

		void printHeap()
		{
			for(int i=0;i<a.size();i++)
			{
				cout<<a[i]<< " ";
			}
		}

		void removeMax()
		{
			if(a.size() < 2)
                        {
				a.clear();
				return;
			}
			
			// Remove first element and replace it with first element.			
			int currentLevel = a.size() - 1;
			int temp = a[currentLevel];
			a[currentLevel] = a[0];
			a[0] = temp;
			a.pop_back();
			currentLevel = 0;
		        int indexToBeReplaced = 0;
			while(currentLevel < a.size()/2 && (a[currentLevel] < a[currentLevel * 2 + 1] || (a.size() > currentLevel*2+2 && a[currentLevel] < a[currentLevel * 2 + 2])))
			{
				int temp = a[currentLevel];
				a[currentLevel] = max(a[currentLevel * 2 + 1], a[currentLevel * 2 + 2]);
				if(a[currentLevel * 2 + 2] > a[currentLevel * 2  + 1] && a.size() > currentLevel*2+2) indexToBeReplaced = currentLevel * 2 + 2 ; 
				else  indexToBeReplaced =  currentLevel * 2  + 1;
				a[indexToBeReplaced] = temp;
				currentLevel = indexToBeReplaced;				
			}
		}
		
};

int main()
{
	Heap *h = new Heap();	
	for(int i=0;i<10;i++)
	{
		h->insert(i+10);
	}
	h->printHeap();
	for(int i=0;i<10;i++)
	{	
		h->removeMax();
		cout<<endl;
		h->printHeap();

	}
}
