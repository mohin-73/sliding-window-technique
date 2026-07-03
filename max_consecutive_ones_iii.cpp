#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        int left = 0, right = 0, mx = 0, z = 0;
        while (right < n) {
            if (nums[right] == 0) {
                ++z;
            }
            while (z > k) {
                if (nums[left] == 0) {
                    --z;
                }
                ++left;
            }
            mx = max(mx, right - left + 1);
            ++right;
        }
        return mx;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    Solution solve;
    cout << solve.longestOnes(nums, k) << '\n';
    return 0;
}

/*
    ------------------
    Problem Statement:
    ------------------

    Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

    ----------
    Example 1:
    ----------

    Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
    Output: 6
    Explanation: [1,1,1,0,0,1,1,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

    ----------
    Example 2:
    ----------

    Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
    Output: 10
    Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
    
    ------------
    Constraints:
    ------------

    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.
    0 <= k <= nums.length
    
*/
