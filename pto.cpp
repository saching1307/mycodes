class Solution {
    public:
    vector<int> maxone(vector<int> Vec, int M)
    {
        int N = Vec.size();
        int i = 0;
        int j = 0;
        int max_len = 0;
        int cnt = 0;
        vector<int> ans;

	       int ans_start = 0;
	        int ans_end = 0;

        while(i < N) {
            if(cnt + (Vec[i] == 0) > M) {
                int temp_len = (i - j); // length from j to i - 1.
                if(temp_len > max_len) {
                        max_len = temp_len;
                        ans_start = j;
			ans_end = i - 1;
                }

                while(i >= j && cnt + (Vec[i] == 0) > M) {
                    cnt -= (Vec[j] == 0);
                    j++;
                }
                cnt += (Vec[i] == 0);
            } else {
                cnt +=(Vec[i] == 0);
            }

            i++;
        }

        int temp_len = (i - j);
        if(temp_len > max_len) {
            temp_len = max_len;
	    ans_start = j;
	    ans_end = i - 1;
        }

	for (int ele = ans_start; ele <= ans_end; ele++) {
		ans.push_back(ele);
	}
	return ans;
    }
};
