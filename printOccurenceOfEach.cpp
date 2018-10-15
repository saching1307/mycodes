#include<iostream>
#include<map>

using namespace std;
void occurenceOfEach(int *array,map<int,int>&integerMap, int start, int end)
{
	int mid = (start + end)/2;

	if(array[start] == array[end])
	{
		integerMap[array[start]] += end - start + 2;
		return;
	}
	else if(array[mid] == array[start])
	{
		integerMap[array[mid]] += mid - start + 1;
		occurenceOfEach(array, integerMap, mid + 1, end);
	}
	else if(array[mid] == array[end])
	{
		integerMap[array[mid]] += end - mid + 1;
		occurenceOfEach(array, integerMap, start, mid - 1);
	}
	else
	{
		occurenceOfEach(array, integerMap, start, mid - 1);
		occurenceOfEach(array, integerMap, mid, end);
	}		
	
}


int main()
{
	int array[10] = {8,8,8,8,9,9,9,9,9,9};
	map<int, int> integerMap;
	
	occurenceOfEach(array, integerMap, 0, 9);
	for(map<int, int>::iterator it = integerMap.begin(); it!=integerMap.end(); it++)
	{
		cout<<it->first<< " "<<it->second<<endl;
	}
}
