#include<iostream>
using namespace std;

int find(int *arr, int n){
    int largest=0, count = 0;
    for(int i=1; i<=n; i++){
        if(arr[i]==1){
            count++;
            
        }
        else{
            count = 0;
        }
    }
    return largest;
}


int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int res = find(arr, n);
    cout << res;

return 0;
}