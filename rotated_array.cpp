#include<iostream>
#include<vector>

using namespace std;

int find_pivot(vector<int> a){
		int start = 0;
		int end = a.size()-1;

		while(start < end){
			int mid = (start + end)/2;
			if( a[mid] < a[mid-1]){
				return mid-1;
			}

			if( a[mid] > a[end]){
				start = mid;
			} else{
				end = mid;
			}
		}

		return 0;
}

int binary_search(vector<int> a, int start, int end, int value){
	while(start < end){
		int mid = (start + end)/2;
		if( a[mid] == value){
			return mid;
		}
		if( a[mid] > value){
			end = mid;
		} else{
			start = mid + 1;
		}
	}

	return -1;
}

int find(std::vector<int> v, int start, int end, int value)
{
		if(start == end){
			return -1;
		}

		int pivot_index = find_pivot(v);
		cout<<"index of pivot "<<pivot_index<<endl;
		int index = binary_search(v, 0, pivot_index, value);
		cout<<"index output "<<index<<endl;

		if(index == -1){
			index = binary_search(v, pivot_index + 1, end, value);
			cout<<"index output "<<index<<endl;
		}

		return index;
}


int main(){

	vector<int> array;

	array.push_back(9);
	array.push_back(11);
	array.push_back(13);
	array.push_back(111);
	array.push_back(411);
	array.push_back(1022);

	cout<<find(array, 0, array.size(), 411 );
}
