#include<iostream>
#include<cmath>

using namespace std;

int calcRank(string a,int maxlength)
{
	int i=0;
	int totalRank = 0;

	while(a[i]!='\0')
	{
		int thisCharacterRank = a[i] - 'a';
		int total = 0;
		for(int k = 0 ; k < maxlength - i - 1 ;k++)
		{
			total += pow(26,k);
		}
		totalRank += thisCharacterRank * total + 1;
		i++;
	}
	return totalRank;
}

int main()
{
	string a = "aaa";
	cout<<calcRank(a, 3)<<endl;
	a = "a";
	cout<<calcRank(a, 3)<<endl;
	a = "ba";
	cout<<calcRank(a, 3)<<endl;
	a = "b";
	cout<<calcRank(a, 3)<<endl;
}
