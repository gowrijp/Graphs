// https://leetcode.com/explore/featured/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3835/
// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
// Return the size of the largest island in grid after applying this operation.
// An island is a 4-directionally connected group of 1s.

// SOLUTION LINK :
// https://leetcode.com/explore/featured/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3835/discuss/1375992/C++Python-DFS-paint-different-colors-Union-Find-Solutions-with-Picture-Clean-and-Concise

/*
Solution: DFS - Paint different connected components by different colors

- The idea is that we dfs to paint different connected components by different colors, 
- we gonna paint in-place on the grid matrix, so we start color from 2, because 0 and 1 is already existed in the grid.
- We need a counter, let componentSize[color] be the size of connected component corresponding to color.
- Iterate over rows and columns in the matrix again, this time we calculate the new size that can be formed if we turn matrix[r][c] from 0 into 1, that is:
If matrix[r][c] == 0 then:
Get color ids of landing neighboring cells to calculate component size. (We get unique color ids to avoid calculating the size of 2 connected component two times)
Calculate total size can be formed.
Update the largest size can be formed so far to our answer.
*/

class Solution {
public:
    const int DIR[5] = {0, 1, 0, -1, 0};
    int m, n;
    unordered_map<int, int> componentSize;
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int ans = 0, nextColor = 2;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != 1) continue; // Only paint when it's an island cell
                paint(grid, r, c, nextColor++);
                ans = max(ans, componentSize[nextColor - 1]);
            }
        }
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != 0) continue; // Skip non-empty cell
                unordered_set<int> neighborColors;
                for (int i = 0; i < 4; ++i) {
                    int nr = r + DIR[i], nc = c + DIR[i+1];
                    if (nr < 0 || nr == m || nc < 0 || nc == n || grid[nr][nc] == 0) continue;
                    neighborColors.insert(grid[nr][nc]);
                }
                int sizeFormed = 1;
                for (int color : neighborColors) sizeFormed += componentSize[color];
                ans = max(ans, sizeFormed);
            }
        }
        return ans;
    }
    void paint(vector<vector<int>>& grid, int r, int c, int color) {
        if (r < 0 || r == m || c < 0 || c == n || grid[r][c] != 1) return;
        grid[r][c] = color;
        componentSize[color] += 1;
        for (int i = 0; i < 4; ++i) paint(grid, r + DIR[i], c + DIR[i+1], color);
    }
};
