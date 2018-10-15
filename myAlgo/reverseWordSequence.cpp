#include<iostream>

using namespace std;
void reverse(char *begin, char* end)
{
	char temp;
	while(begin < end)
	{
	 	temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

void reverseSeq(char *a)
{
	char * word_begin = a;
	char* temp=a;
	while(*temp)
	{
		temp++;
		if(*temp== '\0')
			reverse(word_begin,temp-1);
		if(*temp == ' ')
		{
			reverse(word_begin,temp-1);
			word_begin = temp+1;
		}
	}
	reverse(a,temp-1);
}

int main()
{
	char a[]= "I Love you";
	reverseSeq(a);
	cout<<a;
}
