#include<iostream>
#include<map>

using namespace std;

int main()
{
	string ransomNote = "my name is sachin sabjhfsdjhbsdj ";
	string magazinNote = "sachin is my nam and I eat lot of fish";
	
	map<char, int> noteMap;
	
	for(int i=0;i<26;i++)
	{
		noteMap[i +'a'] = 0;
	}

	int i = 0;
	while(magazinNote[i]!= '\0')
	{
		noteMap[magazinNote[i]]++;
		i++;
	}
	
	i=0;
	while(ransomNote[i]!='\0')
	{
		noteMap[ransomNote[i]]--;
		i++;
	}

	for(int i=0;i<26;i++)
	{
		if(noteMap[i + 'a'] < 0)
		{
			cout<<"match not found for "<< (char)(i + 'a')<<endl;
			exit(0);
		}
	}
	cout<<"Match found"<<endl;


	
}
