from collections import Counter, defaultdict, OrderedDict
from bisect import bisect_left, bisect_right
true = True
false = False
#
# @lc app=leetcode id=688 lang=python3
#
# [688] Knight Probability in Chessboard
#
# https://leetcode.com/problems/knight-probability-in-chessboard/description/
#
# algorithms
# Medium (46.56%)
# Total Accepted:    30K
# Total Submissions: 64.3K
# Testcase Example:  '3\n2\n0\n0'
#
# On an NxN chessboard, a knight starts at the r-th row and c-th column and
# attempts to make exactly K moves. The rows and columns are 0 indexed, so the
# top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
#
# A chess knight has 8 possible moves it can make, as illustrated below. Each
# move is two squares in a cardinal direction, then one square in an orthogonal
# direction.
#
#
#
#
#
#
#
# Each time the knight is to move, it chooses one of eight possible moves
# uniformly at random (even if the piece would go off the chessboard) and moves
# there.
#
# The knight continues moving until it has made exactly K moves or has moved
# off the chessboard. Return the probability that the knight remains on the
# board after it has stopped moving.
#
#
#
# Example:
#
#
# Input: 3, 2, 0, 0
# Output: 0.0625
# Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight
# on the board.
# From each of those positions, there are also two moves that will keep the
# knight on the board.
# The total probability the knight stays on the board is 0.0625.
#
#
#
#
# Note:
#
#
# N will be between 1 and 25.
# K will be between 0 and 100.
# The knight always initially starts on the board.
#
#
#


class Solution:
    def __init__(self):
        self.dirs = [1, 2, 1, -2, -1, 2, -1, -2, 1]
    
    from functools import lru_cache
    @lru_cache(None)
    def find(self, n, k, r, c):
        if r < 0 or c < 0 or r >= n or c >= n:
            return 0
        if k == 0:
            return 1
        if self.dp[r][c][k] > 0:
            return self.dp[r][c][k]
        rate = 0
        for i in range(8):
            rate += 0.125 * self.find(n, k - 1, r +
                                      self.dirs[i], c + self.dirs[i + 1])
        self.dp[r][c][k] = rate
        return rate

    def knightProbability(self, n, k, r, c):
        self.dp = [[[0] * (k + 1) for _ in range(n)] for _ in range(n)]
        return self.find(n, k, r, c)


s = Solution()
print(s.knightProbability(3, 2, 0, 0))
