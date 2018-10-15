#include<iostream>
#include<vector>

using namespace std;


int getLongestConsectiveArray(const char *str)
{
	int i=1;
	int max = 1;
	vector<char> location;
	char prev;
	int continues = 1;
	if(str[0] != '\0')
	{
		prev = str[0];
		location.push_back(prev);
	}
	else
		return 0;
	while(str[i] !='\0')
	{
		if(str[i] == prev)
		{    
			continues++;
		}
		else
		{
			continues = 1;
			prev = str[i];
		}

		if(max < continues)
		{
			max = continues;
			location.erase(location.begin(), location.end());
			location.push_back(str[i]);
		}
		else if(max == continues)
		{
			location.push_back(str[i]);
		} 
		i++;       
	}
	for(vector<char>::iterator it = location.begin(); it != location.end(); it++)
	{
		cout<<*it<<endl;
	}
	return max;
}

int main()
{
	cout<<getLongestConsectiveArray("thiiiis issss aaaa test sentence")<<endl;
	cout<<getLongestConsectiveArray("this is a test ssssssentence")<<endl;
	cout<<getLongestConsectiveArray("this is a test sentenssssssce")<<endl;
}
