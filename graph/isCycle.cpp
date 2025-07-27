#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detect(int src, vector<vector<int>> &adj, vector<bool> &vis){
    queue<pair<int, int>> q;
    vis[src] = true;
    q.push({src, -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it, parent});
            }
            else if(parent != it){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> &adj, vector<bool> &vis){
    for(int i=1; i<=V; i++){
        if(!vis[i]){
        if(detect(i, adj, vis)) return true;
        }
    }
    return true;
}

int main(){
    int V, E, start;
    cin >> V >> E;
    vector<vector<int>> adj(V+1);
    vector<bool> vis(V+1, true);
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
    bool ans = isCycle(start, adj, vis);
    cout << ans;

return 0;
}

