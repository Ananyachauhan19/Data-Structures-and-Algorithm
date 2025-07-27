// Brute - try all subarray and select the maximum sum
/*  maxi = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            sum = 0;
            for(int k=i; k<j; i++){
                sum += arr[k];
            }
            maxi = max(maxi, sum)
        }
    }   TC - O(n^3)
*/


// Better - no need of extra k loop from i to j
/*  maxi = INT_MIN;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            maxi = max(maxi, sum)
        }
    }   TC - O(n^2)
*/

// OPTIMAL - Kadane's Algorithm

#include<iostream>
using namespace std;

int sum(int *arr, int n){
    int max_sum = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        max_sum = max(max_sum, sum);
        if(sum < 0){
            sum = 0;
        }       
    }
    if(max_sum < 0){
        max_sum = 0;
    }

    return max_sum;
}


//Printing subarray

void subPrint(int *arr, int n){
    int max_sum = 0;
    int sum = 0;
    int ans_start = -1, ans_end = -1;
    int start = -1;

    for(int i=0; i<n; i++){
        if(sum == 0) start = i;
        sum += arr[i];
        max_sum = max(max_sum, sum);
        ans_start = start;
        ans_end = i;
        if(sum < 0){
            sum = 0;
        }       
    }
    if(max_sum < 0){
        max_sum = 0;
    }

    for(int i=ans_start; i<ans_end; i++){
        cout << arr[i] << " ";
    }
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // int res = sum(arr, n);
    // cout << res;

    subPrint(arr, n);
    cout << endl;
}