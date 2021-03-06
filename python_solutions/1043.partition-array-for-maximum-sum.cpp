/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 *
 * https://leetcode.com/problems/partition-array-for-maximum-sum/description/
 *
 * algorithms
 * Medium (59.47%)
 * Total Accepted:    3.4K
 * Total Submissions: 5.7K
 * Testcase Example:  '[1,15,7,9,2,5,10]\n3'
 *
 * Given an integer array A, you partition the array into (contiguous)
 * subarrays of length at most K.  After partitioning, each subarray has their
 * values changed to become the maximum value of that subarray.
 *
 * Return the largest sum of the given array after partitioning.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: A = [1,15,7,9,2,5,10], K = 3
 * Output: 84
 * Explanation: A becomes [15,15,15,9,10,10,10]
 *
 *
 *
 * Note:
 *
 *
 * 1 <= K <= A.length <= 500
 * 0 <= A[i] <= 10^6
 *
 */
class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &A, int K) {
    vector<int> dp(A.size(), 0);
    int curmax = 0;
    for (int i = 0; i < A.size(); i++) {
      if (i < K) {
        curmax = max(curmax, A[i]);
        dp[i] = (i + 1) * curmax;
      } else {
        curmax = 0;
        for (int j = 0; j < K; ++j) {
          curmax = max(curmax, A[i - j]);
          dp[i] = max(dp[i], dp[i - j - 1] + curmax * (j + 1));
        }
      }
    }
    return dp.back();
  }
};

static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
