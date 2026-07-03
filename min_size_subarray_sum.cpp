#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int left = 0, right = 0;
        int sum = 0, size = INT_MAX;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                size = min(size, right - left + 1);
                sum -= nums[left++];
            }
            ++right;
        }
        return size == INT_MAX ? 0 : size;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    Solution solve;
    cout << solve.minSubArrayLen(target, nums) << '\n';
    return 0;
}

/*
    ------------------
    Problem Statement:
    ------------------

    Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

    ----------
    Example 1:
    ----------

    Input: target = 7, nums = [2,3,1,2,4,3]
    Output: 2
    Explanation: The subarray [4,3] has the minimal length under the problem constraint.
    Example 2:

    Input: target = 4, nums = [1,4,4]
    Output: 1

    ----------
    Example 3:
    ----------

    Input: target = 11, nums = [1,1,1,1,1,1,1,1]
    Output: 0
    
    ------------
    Constraints:
    ------------

    1 <= target <= 10^9
    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^4
*/
