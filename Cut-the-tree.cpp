// https://www.hackerrank.com/challenges/cut-the-tree/editorial

// SOLUTION :
// DFS on graph
// calculate cumulative weight of each node, i.e. weight of each node + sum of weight of all its children
// difference = abs(total weight - 2*cumulative weight of node n)

#include <bits/stdc++.h>
#define assn(n,a,b) assert(n>=a && n<=b)
#define NMAX 100000
using namespace std;
vector < int > deg[NMAX+10];
int val[NMAX+10],sub[NMAX+10],s=0,ans=INT_MAX;
void foo(int n, int parent)
{
    int i,p=deg[n].size(),ret=val[n];
    for(i=0; i<p; i++)
        if(deg[n][i]!=parent)
        {
            foo(deg[n][i],n);
            ret+=sub[deg[n][i]];
        }
    if(n!=0 && abs(s-2*ret)<ans)ans=abs(s-2*ret);
    sub[n]=ret;
}
int main()
{
    int n,i,j,x,y;
    cin >> n;
    assn(n,3,NMAX);
    for(i=0; i<n; i++)
    {
        cin >> val[i];
        s+=val[i];
        assn(val[i],1,1001);
    }
    for(i=1; i<n; i++)
    {
        cin >> x >> y;
        assn(x,1,n);
        assn(y,1,n);
        x--,y--;
        deg[x].push_back(y);
        deg[y].push_back(x);
    }
    foo(0,-1);
    cout << ans << endl;
    return 0;
}
