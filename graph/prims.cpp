 #include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int INF = 1e9;

void prims(int V, vector<pair<int, int>> adj[]) {
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(inMST[u]) continue;
        inMST[u] = true;

        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(!inMST[v]&& w < key[v]){
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int minCost = 0;

    // Print MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i){
        cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
        minCost += key[i];
    }   

    cout << "MinCost : "<<minCost<<endl;
}


int main() {
    int V = 5;
    vector<pair<int, int>> adj[V];

    // Add undirected edges: u-v with weight
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    prims(V, adj);

    return 0;
}
