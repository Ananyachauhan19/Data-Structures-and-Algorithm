#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int bfs_trav(vector<vector<int>> &adj, vector<bool> &vis, int start, int V){
    queue<int> q;

    q.push(start);
    vis[start]=true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push(it);
            }
        }
    }
}

int main(){
    int V, E, start;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    vector<bool> vis(V, false);
    for(int i=0; i<E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Enter starting node : ";
    cin >> start;
    cout << endl;
    cout << "BFS Traversal \n";
    bfs_trav(adj, vis, start, V);


}