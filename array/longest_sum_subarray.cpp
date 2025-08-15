#include<iostream>
#include<map>
using namespace std;

int find(int *arr, int n, long long k){
    // array with +ve, -ve, zero

    map<long long, int> prefixMap;
    int maxLen = 0;
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        int rem = sum - k;
        if(prefixMap.find(rem) != prefixMap.end()){
            int len  = i - prefixMap[rem];
            maxLen = max(maxLen, len);
        }

        else if(prefixMap.find(sum) == prefixMap.end()){
            prefixMap[sum] = i;
        }
    }


    // Only Positive

    // long long sum = arr[0];
    // int maxLen = 0;
    // int i=0, j=0;
    // while(j < n){
    //     while(i <= j && sum >k){
    //         sum -= arr[i];
    //         i++;
    //     }
    //     if(sum == k){
    //         maxLen = max(maxLen, j-i+1);
    //     }
    //     j++;
    //     if(j<n) sum += arr[j];
    // }
return maxLen;
}


int main(){
    int n;
    long long k;
    cin >> n >> k;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int res = find(arr, n, k);
    cout << res;

return 0;
}