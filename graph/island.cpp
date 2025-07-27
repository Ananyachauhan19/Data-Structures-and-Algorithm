#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col, int n, int m){
    queue<pair<int, int>> q;
    vis[row][col] = 1;
    q.push({row, col});

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int delrow = -1; delrow <= 1; delrow++){
            for(int delcol = -1; delcol <= 1; delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int count(vector<vector<int>> &grid, int n, int m){
    vector<vector<int>> vis(n, vector<int>(m,0));
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                cnt++;
                bfs(grid, vis, i, j, n, m);

            }
        }
    }
    return cnt;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    int res = count(grid, n, m);
    cout << res << endl;
}