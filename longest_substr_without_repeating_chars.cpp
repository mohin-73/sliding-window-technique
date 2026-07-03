#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = static_cast<int>(s.size());
        vector<bool> seen(256, false);
        int left = 0, right = 0, maxLen = 0;
        while (right < n) {
            if (!seen[static_cast<unsigned char>(s[right])]) {
                seen[static_cast<unsigned char>(s[right])] = true;
                ++right;
            } else {
                seen[static_cast<unsigned char>(s[left])] = false;
                ++left;
            }
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "abcabcbb";
    Solution solve;
    cout << solve.lengthOfLongestSubstring(s) << '\n';
    return 0;
}

/*
    ------------------
    Problem Statement:
    ------------------

    Given a string s, find the length of the longest substring without duplicate characters.

    ----------
    Example 1:
    ----------

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

    ----------
    Example 2:
    ----------

    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

    ----------
    Example 3:
    ----------

    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
    
    ------------
    Constraints:
    ------------

    0 <= s.length <= 5 * 10^4
    s consists of English letters, digits, symbols and spaces.
*/
