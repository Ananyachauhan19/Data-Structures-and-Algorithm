#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int comparator(pair<double, int>a, pair<double, int>b){
    return a.first > b.first;
}
double knapsack(vector<int>&profit, vector<int>&weight, int M){

    vector<pair<double, int>> ratio;

    for(int i=0; i<profit.size(); i++){
        double R = (double)profit[i] / weight[i];
        ratio.push_back({R, i});
    }

    sort(ratio.begin(), ratio.end(), comparator);

    double p = 0.0;
    for(int i=0; i<weight.size(); i++){
        int ind = ratio[i].second;

        if(M > 0 && weight[ind] <= M){
            p += profit[ind];
            M -= weight[ind];
        }
        else{
            p += M*ratio[i].first;
            break;
        }
    }
    return p;
}

int main(){
    int M, n;
    cin >> M >> n;

    vector<int> profit(n);
    vector<int> weight(n);

    for(int i=0; i<n; i++){
        cin >> profit[i];
    }

    for(int i=0; i<n; i++){
        cin >> weight[i];
    }

    double pro = knapsack(profit, weight, M);

    cout << "Profit : " << pro << endl;
}