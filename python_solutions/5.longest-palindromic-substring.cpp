/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.16%)
 * Total Accepted:    542.5K
 * Total Submissions: 2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string t(s.rbegin(), s.rend());
        if (s == t) return s; 
        int start = 0, maxlen = 1; 
        for(int i = 0; i < s.size();) {
        	int j = i - 1; 
        	while (s[++i] == s[j+1]); 
        	int k = i; 
        	while (j >= 0 && k <= s.size() - 1 && s[j] == s[k]) {
        		--j, ++k; 
        	}

        	if (k - j - 1 > maxlen) {
        		start = j + 1; 
        		maxlen = k - j - 1;
        	}

        }
        // say(maxlen);
        return s.substr(start, maxlen); 
    }
};



static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL);return 0; }();
