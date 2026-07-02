#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        long long currSum = 0, maxSum = 0;
        int left = 0, right = 0;
        unordered_map<int, int> freq;
        while (right < n) {
            currSum += nums[right];
            ++freq[nums[right]];
            while (freq[nums[right]] > 1) {
                currSum -= nums[left];
                if (--freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                ++left;
            }
            if (right - left + 1 == k) {
                maxSum = max(maxSum, currSum);
                currSum -= nums[left];
                if (--freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                ++left;
            }
            ++right;
        }
        return maxSum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;
    Solution solve;
    cout << solve.maximumSubarraySum(nums, k) << '\n';
    return 0;
}

/*
    ------------------
    Problem Statement:
    ------------------
    
    You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

    The length of the subarray is k, and
    All the elements of the subarray are distinct.
    Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

    A subarray is a contiguous non-empty sequence of elements within an array.
    
    ----------
    Example 1:
    ----------

    Input: nums = [1,5,4,2,9,9,9], k = 3
    Output: 15
    Explanation: The subarrays of nums with length 3 are:
    - [1,5,4] which meets the requirements and has a sum of 10.
    - [5,4,2] which meets the requirements and has a sum of 11.
    - [4,2,9] which meets the requirements and has a sum of 15.
    - [2,9,9] which does not meet the requirements because the element 9 is repeated.
    - [9,9,9] which does not meet the requirements because the element 9 is repeated.
    We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

    ----------
    Example 2:
    ----------

    Input: nums = [4,4,4], k = 3
    Output: 0
    Explanation: The subarrays of nums with length 3 are:
    - [4,4,4] which does not meet the requirements because the element 4 is repeated.
    We return 0 because no subarrays meet the conditions.
    
    ------------
    Constraints:
    ------------

    1 <= k <= nums.length <= 10^5
    1 <= nums[i] <= 10^5
*/
