#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find(int u, vector<int> &parent){
    if(u != parent[u]){
         parent[u] = find(u, parent);
    }
    return parent[u];
}

bool unite(int u, int v, vector<int> &parent, vector<int> &rank){
    int ulp_u = find(u, parent);
    int ulp_v = find(v, parent);
    if(ulp_u == ulp_v) return false;

    if(rank[ulp_u] < rank[ulp_v]){
        parent[ulp_u] = ulp_v;
    }
    else if(rank[ulp_u] > rank[ulp_v]){
        parent[ulp_v] = ulp_u;
    }
    else{
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
    }

    return true;
}

void kruskal(vector<vector<int>> &adj, int V){
    sort(adj.begin(), adj.end());
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for(int i=0; i<V; i++){
        parent[i] = i;
    }
    int min_cost = 0;
    for(auto e : adj){
        int w = e[0];
        int u = e[1];
        int v = e[2];

        if(unite(u, v, parent, rank)){
            min_cost += w;
        }
    }

    cout << "Minimum Cost : "<< min_cost<< endl;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj;

    for(int i=0; i<E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({w, u, v});
    }

    kruskal(adj, V);

return 0;
}