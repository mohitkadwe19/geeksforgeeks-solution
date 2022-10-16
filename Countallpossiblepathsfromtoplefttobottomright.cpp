#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int numberOfPaths(int m, int n)
  {
    vector<vector<long long int>> dp(m, vector<long long int>(n));

    for (int i = 0; i < m; i++)

    {

      for (int j = 0; j < n; j++)

      {

        if (i == 0 || j == 0)

          dp[i][j] = 1;

        else

        {

          dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main()
{
  Solution obj;
  int m = 3, n = 3;
  cout << obj.numberOfPaths(m, n) << endl;
  return 0;
}