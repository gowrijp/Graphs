// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mat[101][101];
int vis[101][101];
int lvl[101][101];

bool safe(int x,int y,int n,int m){
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs(queue<pair<int,int>>Q,int n,int m){
    int row[]={-1,0,0,1};
    int col[]={0,-1,1,0};
    while(!Q.empty()){
        auto p=Q.front();
        Q.pop();
        for(int k=0;k<4;k++){
            if(safe(p.first+row[k],p.second+col[k],n,m) && vis[p.first+row[k]][p.second+col[k]]==0 && mat[p.first+row[k]][p.second+col[k]]==1){
                Q.push(make_pair(p.first+row[k],p.second+col[k]));
                vis[p.first+row[k]][p.second+col[k]]=1;
                lvl[p.first+row[k]][p.second+col[k]]=lvl[p.first][p.second]+1;
            }
        }
    }
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,m,i,j;
	    memset(vis,0,sizeof(vis));
	    memset(lvl,0,sizeof(lvl));
	    queue<pair<int,int>>Q;
	    cin>>n>>m;
	    for(i=0;i<n;i++)
	        for(j=0;j<m;j++)
	            cin>>mat[i][j];
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            if(vis[i][j]==0 && mat[i][j]==2){
	                Q.push(make_pair(i,j));
	                vis[i][j]=1;
	            }
	        }
	    }
	    bfs(Q,n,m);
	    int f=0;
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            if(vis[i][j]==0 && mat[i][j]==1){
	                f=1;
	                cout<<-1<<endl;
	                break;
	            }
	            
	        }
	        if(f==1)
	                break;
	    }
	    int maxx=0;
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            if(lvl[i][j]>maxx){
	                maxx=lvl[i][j];
	            }
	        }
	    }
	    if(f==0){
	        cout<<maxx<<endl;
	    }
	}
	return 0;
}
