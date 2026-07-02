#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = static_cast<int>(arr.size());
        int left = 0, right = 0;
        int sum = 0, cnt = 0;
        while (right < n) {
            sum += arr[right];
            if (right - left + 1 == k) {
                if (sum / k >= threshold) {
                    ++cnt;
                }
                sum -= arr[left];
                ++left;
            }
            ++right;
        }
        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3, threshhold = 4;
    Solution solve;
    cout << solve.numOfSubarrays(nums, k, threshhold) << '\n';
    return 0;
}

/*
    ------------------
    Problem Statement:
    ------------------

    Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

    ----------
    Example 1:
    ----------

    Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
    Output: 3
    Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).

    ----------
    Example 2:
    ----------

    Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
    Output: 6
    Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
    
    ------------
    Constraints:
    ------------

    1 <= arr.length <= 10^5
    1 <= arr[i] <= 10^4
    1 <= k <= arr.length
    0 <= threshold <= 10^4
*/
