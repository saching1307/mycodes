#include<iostream>
#include<string>

using namespace std;

char* getCharsFor(int n)
{
    char *charForNumber = new char(3);
    charForNumber[0] = ((n-1)/3) *3 + 0 + 'a';
    charForNumber[1] = ((n-1)/3) * 3 + 1 + 'a';
    charForNumber[2] = ((n-1)/3) * 3 + 2 + 'a';
    return charForNumber;
}

void printPhonePermutation(int *c, string permutation, int start, int length1)
{
	if(start == length1)
	{
		cout<<permutation<<endl;
		return;
	}

	int length = 3;
	char * letter = getCharsFor(c[start]);
	for(int i=0;i<length;i++)
	{
		printPhonePermutation(c, permutation + letter[i], start + 1, length1);
	}
}


int main()
{
	int number[] = {1,2};
	int n = 2;
	printPhonePermutation(number ,"", 0, n);
}
