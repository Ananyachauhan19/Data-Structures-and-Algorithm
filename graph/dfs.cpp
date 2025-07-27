#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int start, int V) {
    if (start < 0 || start >= V || vis[start]) return;

    cout << start << " ";
    vis[start] = true;
    for (auto it : adj[start]) {
        if (!vis[it]) {
            dfs(adj, vis, it, V);
        }
    }
}

int main() {
    int V, E, start;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    if (V <= 0 || E < 0) {
        cout << "Invalid number of vertices or edges!" << endl;
        return 1;
    }

    vector<vector<int>> adj(V);
    vector<bool> vis(V, false);

    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex in edge " << i + 1 << endl;
            return 1;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    cout << "Enter starting node: ";
    cin >> start;
    if (start < 0 || start >= V) {
        cout << "Invalid starting node!" << endl;
        return 1;
    }

    cout << "DFS traversal: ";
    dfs(adj, vis, start, V);
    cout << endl; 

    return 0;
}