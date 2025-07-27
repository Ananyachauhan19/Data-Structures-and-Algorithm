#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int find(vector<vector<int>> &arr, int n, int m){
    queue<pair<pair<int, int>, int>> q;
    int vis[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    int tm = 0;
    int drow[4] = {-1, 0, +1, 0};
    int dcol[4] = {0, +1, 0, -1};

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < n && arr[nrow][ncol]==1 && vis[nrow][ncol]==0){
                q.push({{nrow, ncol}, t+1});
                vis[nrow][ncol] = 2;
            }
        }        
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1 && vis[i][j]!=2){
                return -1;
            }
        }
    }

    return tm;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int res = find(arr, n, m);
    cout << res;

return 0;
}