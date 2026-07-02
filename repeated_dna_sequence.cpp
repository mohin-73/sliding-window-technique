#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freq;
        vector<string> res;
        string window;
        for (char ch : s) {
            window.push_back(ch);
            if (window.size() == 10) {
                if (++freq[window] == 2) {
                    res.push_back(window);
                }
                window.erase(0, 1);
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution solve;
    vector<string> res = solve.findRepeatedDnaSequences(s);
    for (string str : res) {
        cout << str << '\n';
    }
    return 0;
}

/*
    ------------------
    Problem Statement:
    ------------------
    The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

    For example, "ACGAATTCCG" is a DNA sequence.
    When studying DNA, it is useful to identify repeated sequences within the DNA.

    Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

    ----------
    Example 1:
    ----------

    Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
    Output: ["AAAAACCCCC","CCCCCAAAAA"]

    ----------
    Example 2:
    ----------

    Input: s = "AAAAAAAAAAAAA"
    Output: ["AAAAAAAAAA"]
    
    ------------
    Constraints:
    ------------

    1 <= s.length <= 10^5
    s[i] is either 'A', 'C', 'G', or 'T'.
*/
