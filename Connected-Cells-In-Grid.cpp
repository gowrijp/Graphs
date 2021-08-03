//https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem

#include <bits/stdc++.h>

using namespace std;

int grid[16][16];
bool vis[16][16];
int m,n;

int bfs(int a, int b){
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    
    int k=0;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        if(vis[cur.first][cur.second]){
            continue;
        }
        k++;
        vis[cur.first][cur.second]= true;
        
        for(int di=-1;di<2;di++){
            for(int dj=-1;dj<2;dj++){
                int ci = cur.first + di;
                int cj = cur.second + dj;
                if(ci>=0 and ci<m and cj>=0 and cj<n and !vis[ci][cj] and grid[ci][cj]){
                    q.push(make_pair(ci,cj));
                }
            }
        }
    }
    return k;
}

int main(){
    
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] && !vis[i][j]){
                ans = max(ans, bfs(i,j));
            }
        }
    }
    
    cout<<ans<<endl;
}
