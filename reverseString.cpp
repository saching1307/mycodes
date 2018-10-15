#include<iostream>
#include<map>

using namespace std;

int length(char* str)
{
    int i =0;
    while(str[i] != '\0')
      {
          i++;
       }
      return i;
}

char* revereStr(char *str)
{
        int stringLength = length(str);
        char* newStr = (char*) malloc (sizeof(char) * stringLength);
        for(int i=0; i < stringLength/2 + 1;i++)
        {
            newStr[i] = str[stringLength - i - 1];
            newStr[stringLength - i - 1] = str[i];
        }
        newStr[stringLength] = '\0';
        return newStr;
}

int main()
{
    char input[] = "his is my string";
    cout<<revereStr(input);
}
