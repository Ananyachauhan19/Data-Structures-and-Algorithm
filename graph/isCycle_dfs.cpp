#include<iostream>
#include<vector>
using namespace std;

bool detect(vector<vector<int>> &adj, int parent, int node, vector<int> &vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(detect(adj, node, it, vis)){
                return true;
            }
        }
        else if(it != parent){
            return true;
        }
    }
    return false;
}

int main(){
    int V, E, start;
    cin >> V >> E;
    vector<vector<int>> adj(V+1);
    vector<int> vis(V+1, 0);
     for(int i=1; i<=E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Enter starting node : ";
    cin >> start;
    cout << endl;
    cout << "Cycle Detected : ";
    bool ans = detect(adj, -1, start, vis);
    cout << ans;

return 0;
}
