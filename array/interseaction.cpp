#include<iostream>
#include<vector>
using namespace std;

vector<int> find(int *arr1, int *arr2, int n, int m, vector<int> &res){
    
    int i=0, j=0;
    
    while(i<n && j<m){
        if(arr1[i] < arr2[j]) i++;

        else if(arr1[i] == arr2[j]){
            res.push_back(arr1[i]);
            i++;
            j++;
        }

        else{ j++; }
        
    }

    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];
    vector<int> res;

    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }

    vector<int> result;
    result = find(arr1, arr2, n, m, res);

    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }

return 0;
}