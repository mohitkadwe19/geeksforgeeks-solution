#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int mod = 1e9 + 7;
  int dpMemo(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
  {

    if (i >= 0 && j >= 0 && grid[i][j] == 0)
    {
      return 0;
    }
    if (i == 0 && j == 0)
    {
      return 1;
    }

    if (i < 0 || j < 0)
    {
      return 0;
    }

    if (dp[i][j] != -1)
    {
      return dp[i][j];
    }
    int up = dpMemo(i - 1, j, grid, dp);
    int left = dpMemo(i, j - 1, grid, dp);
    return dp[i][j] = (up + left) % mod;
  }
  int uniquePaths(int n, int m, vector<vector<int>> &grid)
  {
    // code here
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return dpMemo(n - 1, m - 1, grid, dp);
  }
};

int main()
{

  int n = 3, m = 3;
  vector<vector<int>> grid = {
      {1, 1, 1},
      {1, 0, 1},
      {1, 1, 1},
  };
  Solution ob;
  cout << ob.uniquePaths(n, m, grid) << endl;
  return 0;
}