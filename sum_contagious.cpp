#include<iostream>
#include<vector>

using namespace std;

/* Returns true if the there is a subarray of arr[] with sum equal to 'sum'
   otherwise returns false.  Also, prints the result */
int subArraySum(int arr[], int n, int sum)
{
	//sizeof(arr)/sizeof(arr[0])
	
    /* Initialize curr_sum as value of first element
       and starting point as 0 */
    int curr_sum = arr[0], start = 0, i;

    /* Add elements one by one to curr_sum and if the curr_sum exceeds the
       sum, then remove starting element */
    for (i = 1; i <= n; i++)
    {
        // If curr_sum exceeds the sum, then remove the starting elements
        while (curr_sum > sum && start < i-1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        // If curr_sum becomes equal to sum, then return true
        if (curr_sum == sum)
        {
            printf ("Sum found between indexes %d and %d", start, i-1);
            return 1;
        }

        // Add this element to curr_sum
        if (i < n)
          curr_sum = curr_sum + arr[i];
    }

    // If we reach here, then no subarray
    printf("No subarray found");
    return 0;
}

bool check_sum_o(vector<int> a, int value){
		vector<int> array_sum;
		int sum = 0;
		for(int i=0; i<a.size();i++){
				sum  += a[i];
				array_sum.push_back(sum);
				cout<<sum<<" ";
		}

		int n = a.size();
		for(int i = 0; i < a.size(); i++){
				int start = i;
				int end = n;
				while(start < end) {
					int mid = (start + end)/2;
					if (array_sum[mid] - array_sum[i] == value){
							return true;
					} else if(array_sum[mid] - array_sum[i] > value){
							end = mid;
					} else
					{
						start = mid+1;
					}
			}
		}

		return false;
}

bool check_sum(vector<int> a, int i){
		int cur = 0;
		int next = cur + 1;
		while(cur < a.size())
		{
				int sum = 0;
				while(sum < i && cur < a.size())
				{
						sum += a[cur++];
				}

				if(sum == i)
				{
						return true;
				}

				cur = next;
				next++;
		}

		return false;
}

int main(){

	vector<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(40);
	a.push_back(1);
	a.push_back(21);
	a.push_back(2);
	cout<<check_sum_o(a, 61)<<endl;
	cout<<check_sum_o(a, 23)<<endl;
	cout<<check_sum_o(a, 23)<<endl;
	cout<<check_sum_o(a, 2)<<endl;
	cout<<check_sum_o(a, 3)<<endl;
}
