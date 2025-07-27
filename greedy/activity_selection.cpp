#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int comparator(pair<int, int>a, pair<int, int>b){
    return a.second < b.second;
}

void activity(vector<pair<int, int>>&act){
    sort(act.begin(), act.end(), comparator);

    int count = 1;
    int end = act[0].second;

    for(int i= 1; i<act.size(); i++){
        if(end <= act[i].first){

            end = act[i].second;
            count++;

        }
    }

    cout << "Total activities : "<< count<< endl;
}

int main(){

    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);

    for(int i = 0; i<n; i++){
        cin >> vec[i].first >> vec[i].second;
    }

    activity(vec);
return 0;
}