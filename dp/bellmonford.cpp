#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

void bellmanFord(int V, int E, int *u, int *v, int *w, int src) {   
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for(int i=0; i<V-1; i++){
        for(int j=0; j<E; j++){
            if(dist[u[j]] != INT_MAX && dist[u[j]] + w[j] < dist[v[j]]){
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    for (int j = 0; j < E; ++j) {
        if (dist[u[j]] != INT_MAX && dist[u[j]] + w[j] < dist[v[j]]) {
            cout << "Negative weight cycle detected!\n";
            return;
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To vertex " << i << " : ";
        if (dist[i] >= INT_MAX) {
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

    int u[E], v[E], w[E];
    cout << "Enter " << E << " edges (format: u v weight):\n";
    for (int i = 0; i < E; ++i) {
        cin >> u[i] >> v[i] >> w[i];
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    bellmanFord(V, E, u, v, w, src);

    return 0;
}
