using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int bfs(vvi &mat, int n, int m, int x, int y) {
    vvi dist(n, vi(m, -1));
    
    queue<ii> q;
    if (mat[0][0] == 1) {
        q.push(ii(0, 0));
        dist[0][0] = 0;
    }
    
    while (!q.empty()) {
        ii t = q.front(); q.pop();
        int a = t.first, b = t.second;
        if (a == x && b == y)   break;
        static int dx[] = { -1, 1, 0, 0 };
        static int dy[] = { 0, 0, -1, 1 };
        for (int i = 0; i < 4; i++) {
            int c = a + dx[i], d = b + dy[i];
            if (c >= 0 && d >= 0 && c < n && d < m && mat[c][d] == 1 && dist[c][d] == -1) {
                dist[c][d] = dist[a][b] + 1;
                q.push(ii(c, d));
            }
        }
    }
    
    return dist[x][y];
}

int main() {
    int T, n, m, x, y;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        vvi v(n, vi(m));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &v[i][j]);
        
        scanf("%d%d", &x, &y);
        
        printf("%d\n", bfs(v, n, m, x, y));
    }
	return 0;
}
