#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detect(vector<vector<int>> &adj, int node, vector<int> &col){
    queue<int> q;
    q.push(node);

    col[node] = 1;
    while(!q.empty()){
        int n = q.front();
        q.pop();

        for(auto it : adj[n]){
            if(col[it] == -1){
                col[it] = !col[n];
                q.push(it);
            }
            else if(col[it] == col[n]) return false;
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
    cout << "Enter starting node : ";
    cin >> start;
    cout << endl;
    cout << "Bipartite : ";
    bool ans = detect(adj, start, col);
    cout << ans;

return 0;
}
