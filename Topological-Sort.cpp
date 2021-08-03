// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, 
// vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

// Read editorial of this link below
// https://practice.geeksforgeeks.org/problems/topological-sort/1#

#include <bits/stdc++.h>
using namespace std;

// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/

void topologicalSort(vector<int> graph[], int nodes, unordered_map<int, bool> &visited, int start, stack<int> &s) {
    visited[start] = true;
    for (auto node : graph[start]) {
        if (!visited[node]) {
            topologicalSort(graph, nodes, visited, node, s);
        }
    }
    s.push(start);
}

vector<int> topoSort(int nodes, vector<int> graph[]) {
    // Your code here
    unordered_map<int, bool> visited;
    vector<int> answer;
    stack<int> s;
    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            topologicalSort(graph, nodes, visited, i, s);
        }
    }
    
    while (!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    return answer;
}


/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends
