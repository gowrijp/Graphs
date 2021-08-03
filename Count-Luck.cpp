// https://www.hackerrank.com/challenges/count-luck/problem

#include<bits/stdc++.h>
using namespace std;

#define MAXS 100

int totalwaves = 0;
int N, M;
int di, dj;
int graph[MAXS][MAXS];

void DFS(int ri, int rj, int waves = 0) {
    if (ri == di && rj == dj) {
        totalwaves = waves;
        return;
    }

    // Count possible paths
    int pos = 0;
    if (ri - 1 >= 0 && graph[ri-1][rj] != -1) {
        pos++;
    }
    if (ri + 1 < N && graph[ri+1][rj] != -1) {
        pos++;
    }
    if (rj - 1 >= 0 && graph[ri][rj-1] != -1) {
        pos++;
    }
    if (rj + 1 < M && graph[ri][rj+1] != -1) {
        pos++;
    }

    if (pos > 1)
        waves++;

    if (ri - 1 >= 0 && graph[ri-1][rj] != -1) {
        graph[ri-1][rj] = -1;
        DFS(ri-1, rj, waves);
    }
    if (ri + 1 < N && graph[ri+1][rj] != -1) {
        graph[ri+1][rj] = -1;
        DFS(ri+1, rj, waves);
    }
    if (rj - 1 >= 0 && graph[ri][rj-1] != -1) {
        graph[ri][rj-1] = -1;
        DFS(ri, rj-1, waves);
    }
    if (rj + 1 < M && graph[ri][rj+1] != -1) {
        graph[ri][rj+1] = -1;
        DFS(ri, rj+1, waves);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        int si, sj;
        for (int i = 0; i < N; i++) {
            string input;
            cin >> input;

            for (int j = 0; j < M; j++) {
                char ch = input[j];
                if (ch == '.') {
                    graph[i][j] = 0;
                }
                else if (ch == 'X') {
                    graph[i][j] = -1;
                }
                else if (ch == 'M') {
                    graph[i][j] = -1;
                    si = i;
                    sj = j;
                }
                else {
                    di = i;
                    dj = j;
                    graph[i][j] = 0;
                }
            }
        }
        int K;
        cin >> K;

        DFS(si, sj);
        if (totalwaves == K)
            cout << "Impressed";
        else
            cout << "Oops!";

        cout << "\n";
    }
    return 0;
}
