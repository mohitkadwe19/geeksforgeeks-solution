#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool helper(int arr[], int ind, int target, vector<vector<int>> &dp)
  {
    if (target == 0)
      return true;
    if (ind == 0)
      return arr[0] == target;
    if (dp[ind][target] != -1)
      return dp[ind][target];

    bool take = false;

    if (arr[ind] <= target)
      take = helper(arr, ind - 1, target - arr[ind], dp);

    bool nottake = false;
    nottake = helper(arr, ind - 1, target, dp);
    return dp[ind][target] = (take or nottake);
  }
  int equalPartition(int N, int arr[])
  {
    int sum = 0;
    for (int i = 0; i < N; i++)
      sum += arr[i];
    if (sum % 2)
      return 0;
    int target = sum / 2;
    vector<vector<int>> dp(N + 1, vector<int>(target + 1, -1));
    return helper(arr, N - 1, target, dp);
  }
};

int main()
{
  int N = 4;
  int arr[] = {1, 5, 11, 5};
  Solution obj;
  cout << obj.equalPartition(N, arr);
}