#include<iostream>
#include<vector>

using namespace std;

bool check_if_subset(std::vector<int> a, std::vector<int> b){
	 if(b.size() > a.size()){
		 return false;
	 }

	 sort(a.begin(), a.end());
	 sort(b.begin(), b.end());
	 int mainArrayCounter =0;

	 for(int i=0; i<b.size();i++){
		 // this step can be done in binary search
		 	while(a[mainArrayCounter++] != b[i]){
					if(mainArrayCounter > a.size()){
						return false;
				}
			}
	 }

	 return true;
}

int main()
{
	std::vector<int> a;
	std::vector<int> b;

	a.push_back(1);
	a.push_back(11);
	a.push_back(121);
	a.push_back(4);
	a.push_back(5);

	b.push_back(4);
	b.push_back(51);

	cout<<check_if_subset(a, b);

}
