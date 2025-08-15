#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> find(int *arr1, int *arr2, int n, int m, vector<int> &res){

    int i=0, j=0;

    if (res.empty()) {
        if (arr1[i] <= arr2[j]) {
            res.push_back(arr1[i]);
            i++;
        } else {
            res.push_back(arr2[j]);
            j++;
        }
    }

    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            if(res.back() != arr1[i]){
                res.push_back(arr1[i]);
                i++;
            }
            else{
                i++;
            }
        }
        else{
            if(res.back() != arr2[j]){
                res.push_back(arr2[j]);
                j++;
            }
            else{
                j++;
            }
        }
    }

    while(i<n){
        if(res.back()!=arr1[i]){
            res.push_back(arr1[i]);
            i++;
        }
        else{
            i++;
        }
    }

    while(j<m){
        if(res.back()!=arr2[j]){
            res.push_back(arr2[j]);
            j++;
        }
        else{
            j++;
        }
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