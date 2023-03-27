#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int fun(int sum, int curr, int k, vector<vector<vector<int>>> &dp)
  {
    if (sum < 0 or curr == 0)
      return 0;
    if (k == 0)
    {
      if (sum == 0)
        return 1;
      return 0;
    }
    if (dp[sum][curr][k] != -1)
      return dp[sum][curr][k];

    return dp[sum][curr][k] = fun(sum, curr - 1, k, dp) + fun(sum - curr, curr, k - 1, dp);
  }
  int countWaystoDivide(int n, int k)
  {
    // Code here
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
    int x = n - k + 1;
    if (x == 2 or x == 1)
      return 1;
    return fun(n, n - k + 1, k, dp);
  }
};

int main()
{

  int N = 8, K = 4;
  Solution ob;
  cout << ob.countWaystoDivide(N, K) << endl;
  return 0;
}