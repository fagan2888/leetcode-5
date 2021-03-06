// C libraries
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// Containers
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Input/Output
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

// Other
#include <algorithm>
#include <bitset>
#include <chrono>
#include <iterator>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

// ==================================================

using namespace std;

// constants
const double EPS = 1e-9;
const int MOD = 1000000007;

// type alias
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvi = vector<vector<int>>;
using vvs = vector<vector<string>>;
using mii = map<int, int>;
using mci = map<char, int>;
using si = set<int>;
using spii = set<pair<int, int>>;
using umii = unordered_map<int, int>;
using umci = unordered_map<char, int>;
using umsi = unordered_map<string, int>;
using usi = unordered_set<int>;
using usc = unordered_set<char>;
using uss = unordered_set<string>;
using vpii = vector<pair<int, int>>;

typedef struct TreeNode TreeNode;
using ptn = TreeNode *;
using tn = TreeNode;

// ==================================================

// fast IO
static auto __speedup__ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ==================================================

// some macro for less typing
#define forloop(i, n) for (int i = 0; i < n; i++)             //[0, n)
#define forloopr(i, n) for (int i = n - 1; i >= 0; --i)       // reverse [0, n)
#define forloopup(i, a, b) for (int i = a; i < b; ++i)        // [a, b)
#define forloopdown(i, a, b) for (int i = b - 1; i >= a; --i) // reverse [a, b)
#define forunfold(i, arr) for (auto &i : arr)

#define INF 0x3f3f3f3f
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define ef emplace_front
#define eb emplace_back
#define qall(v) v.begin(), v.end()
#define qsize(v) (int)v.size()
#define qsort(v) sort(v.begin(), v.end())
#define rqsort(v) sort(v.rbegin(), v.rend())
#define qreverse(v) reverse(v.begin(), v.end())

// int to string
string itos(int n) { return to_string(n); }
// char to string
string ctos(char c) { return string(1, c); };

inline string upper(string s) {
  string t(s);
  transform(t.begin(), t.end(), t.begin(), ::toupper);
  return t;
}
inline string lower(string s) {
  string t(s);
  transform(t.begin(), t.end(), t.begin(), ::tolower);
  return t;
}

int dirs[5] = {-1, 0, 1, 0, -1};

// ==================================================
/*
 * @lc app=leetcode id=1553 lang=cpp
 *
 * [1553] Minimum Number of Days to Eat N Oranges
 *
 * https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/description/
 *
 * algorithms
 * Hard (26.76%)
 * Total Accepted:    8.5K
 * Total Submissions: 31.3K
 * Testcase Example:  '10'
 *
 * There are n oranges in the kitchen and you decided to eat some of these
 * oranges every day as follows:
 *
 *
 * Eat one orange.
 * If the number of remaining oranges (n) is divisible by 2 then you can eat
 * n/2 oranges.
 * If the number of remaining oranges (n) is divisible by 3 then you can eat
 * 2*(n/3) oranges.
 *
 *
 * You can only choose one of the actions per day.
 *
 * Return the minimum number of days to eat n oranges.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 10
 * Output: 4
 * Explanation: You have 10 oranges.
 * Day 1: Eat 1 orange,  10 - 1 = 9.
 * Day 2: Eat 6 oranges, 9 - 2*(9/3) = 9 - 6 = 3. (Since 9 is divisible by 3)
 * Day 3: Eat 2 oranges, 3 - 2*(3/3) = 3 - 2 = 1.
 * Day 4: Eat the last orange  1 - 1  = 0.
 * You need at least 4 days to eat the 10 oranges.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 6
 * Output: 3
 * Explanation: You have 6 oranges.
 * Day 1: Eat 3 oranges, 6 - 6/2 = 6 - 3 = 3. (Since 6 is divisible by 2).
 * Day 2: Eat 2 oranges, 3 - 2*(3/3) = 3 - 2 = 1. (Since 3 is divisible by 3)
 * Day 3: Eat the last orange  1 - 1  = 0.
 * You need at least 3 days to eat the 6 oranges.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 * Example 4:
 *
 *
 * Input: n = 56
 * Output: 6
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2*10^9
 *
 */
unordered_map<int, int> dp;
class Solution {
public:
  int minDays(int n) { return dfs(n); }

  int dfs(int n) {
    if (n <= 2)
      return n;
    if (dp.count(n))
      return dp[n];
    dp[n] = 1 + min(n % 2 + dfs(n / 2), n % 3 + dfs(n / 3));
    // Compress the following codes in one line. E.g.,
    // 3 / 3 = 4 / 3 = 5 / 3, the only difference is the steps required
    // to reduce n + k to n (k == 0, 1, 2)
    return dp[n];
    // if (n % 2 == 0)
    //   res = min(res, 1 + dfs(n / 2));
    // if (n % 3 == 0)
    //   res = min(res, 1 + dfs(n / 3));
    // if ((n - 1) % 2 == 0 || (n - 1) % 3 == 0)
    //   res = min(res, 1 + dfs(n - 1));
    // if ((n - 2) % 3 == 0)
    //   res = min(res, 2 + dfs(n - 2));
    // return dp[n] = res;
  }
};

auto speed_up = []() {
  ios_base::sync_with_stdio(false);
  return 0;
}();
