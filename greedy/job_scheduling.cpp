#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void job(vector<int>&id, vector<int>&deadline, vector<int>&profit){
    vector<pair<int, pair<int, int>>> job_schedule;

    for(int i = 0; i<id.size(); i++){
        job_schedule.push_back({profit[i], {deadline[i], id[i]}});
    }

    sort(job_schedule.begin(), job_schedule.end(), greater<>());
    int max_deadline = 0;
    for(int i =0; i<id.size(); i++){
        max_deadline = max(max_deadline, job_schedule[i].second.first);
    }

    vector<int> slot(max_deadline+1, -1);
    int count = 0;
    int max_profit = 0;

    for(int i = 0; i< id.size(); i++){
        int job_id = job_schedule[i].second.second;
        int p = job_schedule[i].first;
        int d = job_schedule[i].second.first;
        for(int j = d; j>=1; j--){
            if(slot[j] == -1){
                slot[j] = job_id;
                count++;
                max_profit += p;
                break;
            }
        }

    }

    cout << "Total Jobs Done: " << count << endl;
    cout << "Total Profit: " << max_profit << endl;
}

int main(){
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    vector<int> id(n), deadline(n), profit(n);
    cout << "Enter Job IDs: ";
    for (int i = 0; i < n; ++i) cin >> id[i];
    cout << "Enter Deadlines: ";
    for (int i = 0; i < n; ++i) cin >> deadline[i];
    cout << "Enter Profits: ";
    for (int i = 0; i < n; ++i) cin >> profit[i];

    job(id, deadline, profit);
    return 0;

}