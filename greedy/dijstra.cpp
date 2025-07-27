#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

void dijkstras(int V, vector<vector<pair<int,int>>> &adj, int src) {   
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(dist[u] < d) continue;

        for(auto i : adj[u]){
            int v = i.first;
            int w = i.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To vertex " << i << " : ";
        if (dist[i] == INT_MAX) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter " << E << " edges (format: u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graph
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstras(V, adj, src);

    return 0;
}
