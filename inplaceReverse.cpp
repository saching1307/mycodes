#include<iostream>
using namespace std;

void reverse(char*arr, int start, int end)
{
    for(int i = 0; i < ( end- start)/2 + 1;i++)
    {
        char temp = arr[start+ i];
        arr[start + i] = arr[end - i];
        arr[end - i] = temp;
    }
}

void inplace_reverse(char* arr)
{
	int i = 0;
	int prevIndex = 0;
	while(arr[i] != '\0' && i < 30)
	{
		if(isspace(arr[i]))
		{
			if(prevIndex!=i-1)
			{	
				reverse(arr, prevIndex + 1, i-1);
			}
			prevIndex = i;
		}
		i++;
	}
	reverse(arr, prevIndex + 1, i-1);
	reverse(arr, 0, i-1);
}


int main()
{
	string s = "I wish you a merry Christmas";
	char* input =  strdup(s.c_str());;
	cout<<input<<endl;
	inplace_reverse(input);
	cout<<input<<endl;

}
