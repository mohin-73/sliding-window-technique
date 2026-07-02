#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = static_cast<int>(s1.size());
        int len2 = static_cast<int>(s2.size());
        if (len1 > len2) {
            return false;
        }
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        int left = 0, right = 0;
        for (int i = 0; i < len1; ++i) {
            ++freq1[s1[i] - 'a'];
        }
        while (right < len2) {
            ++freq2[s2[right] - 'a'];
            if (right - left + 1 == len1) {
                if (freq1 == freq2) {
                    return true;
                }
                --freq2[s2[left] - 'a'];
                ++left;
            }
            ++right;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1 = "ab", s2 = "eidbaooo";
    Solution solve;
    if (solve.checkInclusion(s1, s2)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    return 0;
}

/*
    ------------------
    Problem Statement:
    ------------------

    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

    In other words, return true if one of s1's permutations is the substring of s2.

    ----------
    Example 1:
    ----------

    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").
    Example 2:

    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false
    
    ------------
    Constraints:
    ------------

    1 <= s1.length, s2.length <= 10^4
    s1 and s2 consist of lowercase English letters.
*/
