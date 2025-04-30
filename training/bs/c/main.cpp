#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l =1, r = nums.size();

		while (l < r) {
			int m = (l + r) / 2;
			if (nums[0] < nums[m]){
				l = m + 1;
			} else {
				r = m;
			}
		}

		return nums[l % nums.size()];
    }
};


