
# Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
#
# click to show follow up.
#
# Follow up:
# Did you use extra space?
# A straight forward solution using O(mn) space is probably a bad idea.
# A simple improvement uses O(m + n) space, but still not the best solution.
# Could you devise a constant space solution?

# @param {Integer[][]} matrix
# @return {Void} Do not return anything, modify matrix in-place instead.


class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        a = 3.1415926
        m, n = len(matrix), len(matrix[0])
        for i in range(m):
            rset = False
            for j in range(n):
                if not matrix[i][j]:
                    if not rset:
                        rset = True
                        matrix[i] = [
                            0 if not matrix[i][k] else a for k in range(n)]
                    for k in range(m):
                        matrix[k][j] = a if matrix[k][j] else 0

        for i in range(m):
            for j in range(n):
                matrix[i][j] = 0 if matrix[i][j] == a else matrix[i][j]
        print(matrix)


ma = [[1, 0, 0, 3],
      [2, 1, 3, 2],
      [2, 0, 5, 4],
      [7, 8, 2, 9]]
s = Solution()
s.setZeroes(ma)
