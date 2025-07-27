#include<iostream>
#include<vector>
using namespace std;

bool detect(vector<vector<int>> &adj, int node, int c, vector<int> &col){
    col[node] = c;
    for(auto i : adj[node]){
        if(col[i] == -1){
            if(!detect(adj, i, !c, col)){
                return false;
            }
        }
        else if(col[i] == col[node]){
            return false;
        }
    }
    return true;
}

int main(){
    int V, E, start;
    cin >> V >> E;
    vector<vector<int>> adj(V+1);
    vector<int> col(V+1, -1);
     for(int i=1; i<=E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isBipartite = true;
    for(int i=1; i<=V; i++){
        if(col[i] == -1){
            if(!detect(adj, i, 0, col)){
                isBipartite = false;
                break;
            }
        }
    }
   if (isBipartite)
        cout << "Graph is Bipartite.\n";
    else
        cout << "Graph is NOT Bipartite.\n";

return 0;
}
