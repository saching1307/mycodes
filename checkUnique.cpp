#include<iostream>
#include<map>

using namespace std;

bool checkIfStringHasUniqueCharacters(string a)
{
    map<char, int> characterCount;
    for(int i=0;i<26;i++)
    {
        characterCount[i + 'a'] = 0;    
    }    
    
    int i=0;
    while(a[i]!='\0')
    {
        characterCount[a[i]]++;
        i++;
    }
    
    for(int i=0;i<26;i++)
    {
        if(characterCount[i + 'a'] > 1)
            {
                return false;
             }
    } 
    return true;
}

int main()
{
    string input = "this";
    cout<< checkIfStringHasUniqueCharacters(input);
}
