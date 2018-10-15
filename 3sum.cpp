#include<iostream>
#include<vector>

using namespace std;

void check_3_sum(std::vector<int> v){

		if(v.size() < 3){
			return;
		}
		int n = v.size();
		sort(v.begin(), v.end());
		int small = v[0];
		int mid = v[n-2];
		int end = v[n];
		for(int k=2; k<n-2;k++){
			end = v[k];
			small = v[0];
			mid = v[k-1];
			while(small < mid){
				if(small + mid == end){
					cout<< small << " "<<mid<< " "<< end<<endl;
					small++;
					mid--;
				}
				else if( small + mid > end){
						mid--;
				} else{
					small++;
				}
			}
		}
}

int main()
{
	vector<int> input;

	input.push_back(1);
	input.push_back(4);
	input.push_back(4);
	input.push_back(7);
	input.push_back(19);
	input.push_back(12);
	input.push_back(21);
	input.push_back(6);
	input.push_back(2);

	check_3_sum(input);
}
