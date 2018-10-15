#include<iostream>

using namespace std;

/* Function recursively prints the strings having space pattern.
   i and j are indices in 'str[]' and 'buff[]' respectively */
void printPatternUtil(char str[], char buff[], int i, int j, int n)
{
    if (i==n)
    {
        buff[j] = '\0';
        cout << buff << endl;
        return;
    }
 
    // Either put the character
    buff[j] = str[i];
    printPatternUtil(str, buff, i+1, j+1, n);
 
    // Or put a space followed by next character
    buff[j] = ' ';
    buff[j+1] = str[i];
 
    printPatternUtil(str, buff, i+1, j+2, n);
}
 
// This function creates buf[] to store individual output string and uses
// printPatternUtil() to print all permutations.
void printPattern(char *str)
{
    int n = strlen(str);
 
    // Buffer to hold the string containing spaces
    char buf[2*n]; // 2n-1 characters and 1 string terminator
 
    // Copy the first character as it is, since it will be always
    // at first position
    buf[0] = str[0];
 
    printPatternUtil(str, buf, 1, 1, n);
}

void printPattern1(string str, string prefix ,int start, int end)
{
	if(start == end) 
	{ 
		cout<<prefix<<endl; 
		return;
	}
	printPattern1(str, prefix + str[start], start + 1, end);
	printPattern1(str, prefix + " " +str[start], start + 1, end);
}
int main()
{
	char str[10];
	str[0] = 'A';
	str[1] = 'B';
	str[2] = 'C';
	str[3] = 'D';
	str[4] = '\0';
    	string str1 = "ABCDE";
	printPattern1(str1,"A",1,str1.length());
    //printPattern(str);
    return 0;
}




