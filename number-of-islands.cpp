// https://leetcode.com/problems/number-of-islands/

// SIMPLER RECURSIVE SOLUTION WITH NO EXTRA VISITED ARRAY USED ***
class Solution {
public:
    //mark all the land as '2' of current island
    void solve(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != '1') return;
        grid[i][j] = '2';
        
        solve(grid, i-1, j, m, n);
        solve(grid, i+1, j, m, n);
        solve(grid, i, j-1, m, n);
        solve(grid, i, j+1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        if(m == 0) return 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '1'){
                    solve(grid, i, j, m, n);
                    ans++;
                }
        return ans;
    }
};

// My SOLUTION (BFS)

class Solution {
public:
    bool vis[300][300];
    void bfs(int a, int b, int m, int n, vector<vector<char>> grid){
        queue<pair<int,int>> q;
        q.push(make_pair(a,b));

        int row[]={-1,0,0,1};
        int col[]={0,-1,1,0};
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            if(vis[cur.first][cur.second]){
                continue;
            }
            vis[cur.first][cur.second]= true;
            
            for(int k=0;k<4;k++){
                int ci = cur.first + row[k];
                int cj = cur.second + col[k];
                if(ci>=0 and ci<m and cj>=0 and cj<n and !vis[ci][cj] and grid[ci][cj]== '1'){
                    q.push(make_pair(ci,cj));
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        memset(vis,0,sizeof(vis));

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(i,j,m,n, grid);
                    ans++;
                }
            }
        }

        //cout<<ans<<endl;
        return ans;
    }
    
};
