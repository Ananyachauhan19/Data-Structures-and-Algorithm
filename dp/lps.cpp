#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longest(int ind1, int ind2, string str1, string str2, vector<vector<int>>& dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (str1[ind1] == str2[ind2])
    {
        return dp[ind1][ind2] = 1 + longest(ind1 - 1, ind2 - 1, str1, str2, dp);
    }
    else
    {
        return dp[ind1][ind2] = max(longest(ind1 - 1, ind2, str1, str2, dp), longest(ind1, ind2 - 1, str1, str2, dp));
    }
}

string getlcs(string str1, string str2, vector<vector<int>>& dp)
{
    int i = str1.length() - 1;
    int j = str2.length() - 1;

    string str = "";

    while (i >= 0 && j >= 0)
    {
        if (str1[i] == str2[j])
        {
            str += str1[i];
            i--;
            j--;
        }
        else
        {
            if (i > 0 && dp[i - 1][j] >= dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    string str1;
    cin >> str1;

    int n = str1.length();
    string str2 = str1;
    int m = str2.length();
    
    reverse(str2.begin(), str2.end());

    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << longest(n - 1, m - 1, str1, str2, dp) << endl;
    cout << getlcs(str1, str2, dp);

    return 0;
}