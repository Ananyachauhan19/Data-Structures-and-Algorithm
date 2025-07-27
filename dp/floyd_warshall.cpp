#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = 1e9; 

void floydWarshall(int V, vector<vector<int>>& dist) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        if (dist[i][i] < 0) {
            cout << "Negative weight cycle detected!\n";
            return;
        }
    }

    cout << "\nShortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] >= INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> dist(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i)
        dist[i][i] = 0; 

    cout << "Enter " << E << " edges (format: u v weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w; 
    }

    floydWarshall(V, dist);

    return 0;
}
