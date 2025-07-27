// POSITIVE AND NEGTAIVE ARE NOT EQUAL

#include<iostream>
#include<vector>
using namespace std;

vector<int> Print(vector<int> &arr, int n){
    vector<int> pos;
    vector<int> neg;

    for(int i=0; i<n; i++){
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    for(int i=0; i<n/2; i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }

    if(pos.size() > neg.size()){
        for(int i=0; i<neg.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;

        for(int i=neg.size(); i<pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i=0; i<pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }

        int index = pos.size() * 2;

        for(int i=pos.size(); i<neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }

    }
    return arr;
}

int main(){
    int n;
    cin >> n;
    vector<int> newArr;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    newArr = Print(arr, n);
    for(int i=0; i<n; i++){
        cout << newArr[i]<< " ";
    }
    cout << endl;
}