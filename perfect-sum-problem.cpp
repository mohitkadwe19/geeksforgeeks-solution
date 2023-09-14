#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

class Solution
{
public:
  int perfectSum(int arr[], int n, int sum)
  {
    vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 0));

    dp[0][0] = 1;
    for (int i = 1; i < sum + 1; i++)
    {
      dp[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
      for (int j = 0; j < sum + 1; j++)
      {

        if (arr[i - 1] > j)
        {
          dp[i][j] = dp[i - 1][j] % mod;
        }
        else
        {
          dp[i][j] = (dp[i - 1][j] % mod + dp[i - 1][j - arr[i - 1]] % mod) % mod;
        }
      }
    }
    return dp[n][sum];
  }
};

int main()
{
  int N = 6;
  int arr[] = {2, 3, 5, 6, 8, 10};
  int sum = 10;
  Solution ob;
  cout << ob.perfectSum(arr, N, sum) << endl;
  return 0;
}