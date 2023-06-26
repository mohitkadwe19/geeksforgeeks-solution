#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  const int mod = 1e9 + 7;
  int nCr(int n, int r)
  {
    if (n < r)
      return 0;
    vector<vector<int>> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
      dp[i] = vector<int>(i + 1, 1);
      for (int j = 1; j < i; j++)
      {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
      }
    }
    return dp[n][r] % mod;
  }
};

int main()
{
  int n = 3, r = 2;
  Solution ob;
  cout << ob.nCr(n, r) << endl;
  return 0;
}