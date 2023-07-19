#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestPalinSubseq(string A)
  {
    int n = A.length();
    int dp[n][n];
    for (int i = 0; i < n; i++)
      dp[i][i] = 1;
    for (int i = 2; i <= n; i++)
    {
      for (int j = 0; j < n - i + 1; j++)
      {
        int k = j + i - 1;
        if (A[j] == A[k] && i == 2)
        {
          dp[j][k] = 2;
        }
        else if (A[k] == A[j])
        {
          dp[j][k] = 2 + dp[j + 1][k - 1];
        }
        else
        {
          dp[j][k] = max(dp[j + 1][k], dp[j][k - 1]);
        }
      }
    }
    return dp[0][n - 1];
  }
};

int main()
{
  Solution s;
  string A = "bbabcbcab";
  cout << s.longestPalinSubseq(A);
  return 0;
}