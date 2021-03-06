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
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 *
 * https://leetcode.com/problems/minimum-cost-for-tickets/description/
 *
 * algorithms
 * Medium (60.63%)
 * Total Accepted:    58K
 * Total Submissions: 94.6K
 * Testcase Example:  '[1,4,6,7,8,20]\n[2,7,15]'
 *
 * In a country popular for train travel, you have planned some train
 * travelling one year in advance.  The days of the year that you will travel
 * is given as an array days.  Each day is an integer from 1 to 365.
 *
 * Train tickets are sold in 3 different ways:
 *
 *
 * a 1-day pass is sold for costs[0] dollars;
 * a 7-day pass is sold for costs[1] dollars;
 * a 30-day pass is sold for costs[2] dollars.
 *
 *
 * The passes allow that many days of consecutive travel.  For example, if we
 * get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6,
 * 7, and 8.
 *
 * Return the minimum number of dollars you need to travel every day in the
 * given list of days.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: days = [1,4,6,7,8,20], costs = [2,7,15]
 * Output: 11
 * Explanation:
 * For example, here is one way to buy passes that lets you travel your travel
 * plan:
 * On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
 * On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3,
 * 4, ..., 9.
 * On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
 * In total you spent $11 and covered all the days of your travel.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
 * Output: 17
 * Explanation:
 * For example, here is one way to buy passes that lets you travel your travel
 * plan:
 * On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1,
 * 2, ..., 30.
 * On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
 * In total you spent $17 and covered all the days of your travel.
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= days.length <= 365
 * 1 <= days[i] <= 365
 * days is in strictly increasing order.
 * costs.length == 3
 * 1 <= costs[i] <= 1000
 *
 *
 */

/*
Let minCost(i) denote the minimum cost that will be payed for all trips on days
1 to day 365. The desired answer is then minCost(365).

Calculation minCost(i):

If no trip on day i, then minCost(i) = minCost(i-1).
minCost(i)=0 for all i ≤ 0.
Otherwise:
If a 1-day pass on day i. In this case, minCost(i) = minCost(i) + costs[0].
If a 7-day pass ending on day i. then : In this case, minCost(i) = min(minCost(i
− 7), minCost(i − 6), …, minCost(i − 1)) + costs[1]. But since since minCost is
increasing (adding a day never reduces the minCost) hence: minCost(i) =
minCost(i − 7) + costs[2]

*/
class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    int dp[366] = {0};
    unordered_set<int> cc(qall(days));
    forloopup(i, 1, 366) {
      if (cc.find(i) == cc.end())
        dp[i] = dp[i - 1];
      else
        dp[i] = min({dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1],
                     dp[max(0, i - 30)] + costs[2]});
    }
    return dp[365];
  }
};

auto speed_up = []() {
  ios_base::sync_with_stdio(false);
  return 0;
}();
