#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> updateQuery(int N, int Q, vector<vector<int>> &U)
  {
    vector<int> ans(N, 0);
    vector<vector<int>> dp(N, vector<int>(31, 0));

    for (int i = 0; i < Q; i++)
    {
      int l = U[i][0] - 1;
      int r = U[i][1];
      int x = U[i][2];
      for (int j = 0; j < 31; j++)
      {
        int mask = 1 << j; // one left shift by j so if mask and x tends to one then increment;
        if (mask & x)
        {
          dp[l][j]++;
          if (r < N)
            dp[r][j]--;
        }
      }
    }

    for (int i = 1; i < N; i++)
      for (int j = 0; j < 31; j++)
        dp[i][j] += dp[i - 1][j];

    for (int i = 0; i < N; i++)
    {
      int temp = 0;

      for (int j = 0; j < 31; j++)
        if (dp[i][j])
          temp |= (1 << j); // or gate add the values

      ans[i] = temp;
    }

    return ans;
  }
};

int main()
{
  int N = 3, Q = 2;
  vector<vector<int>> U = {{1, 3, 1}, {1, 3, 2}};
}