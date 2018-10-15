#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> a)
{
	for(int i=0;i<a.size();i++)
	{
			cout<<a[i]<< " ";
	}
	cout<<endl;
}

vector<int> generate_prefix(string s){
	int known = 0;
	vector<int> v;
	for(int i = 0 ; i <s.size() ;i++)
	{
			known = 0;
			for(int j = 0; j< i; j++)
			{
					if(i<s.size() && s[i] == s[known])
					{
						known++;
						i++;
						v.push_back(known);
					} else{
						known = 0;
						break;
					}
			}

			if(i<s.size()) {
				v.push_back(known);
			}
	}

  printVector(v);
	return v;
}

int mystrstr(string text, string pattern){
		vector<int> output = generate_prefix(pattern);
		int n = text.size();
		int m = pattern.size();
		int i=0, j=0, k=0;
		while(n - k + 1>= m){
			while(j <= m && text[i] == pattern[j]){
				 i++;
				 j++;
			 }

			 if(j >=m)
			 {
				 cout<< k<<endl;
			 }


			 if(j>1 && output[j-1]>0){
				 k = i - output[j-1];
			 } else{
				 if (i == k) i = i+1;
				 k = i;
			 }
			 if(j>1){
				 j = output[j-1];
			 }

		}
		return -1;
}



int main(){
	mystrstr("sachsachsachsach","sachsach");
}
