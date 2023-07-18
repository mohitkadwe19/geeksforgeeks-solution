#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int LongestRepeatingSubsequence(string str)
  {
    string s = str;
    int n = str.size();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
      dp[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
      dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (str[i - 1] == s[j - 1] && i != j)
        {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[n][n];
  }
};

int main()
{
  Solution s;
  string str = "axxzxy";
  cout << s.LongestRepeatingSubsequence(str);
  return 0;
}