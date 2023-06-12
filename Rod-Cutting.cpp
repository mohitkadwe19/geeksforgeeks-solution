#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int cutRod(int price[], int n)
  {
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
      dp[i][0] = 0;
    for (int i = 0; i <= n; i++)
      dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
      {
        if (i <= j)
          dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - i]);
        else
          dp[i][j] = dp[i - 1][j];
      }
    return dp[n][n];
  }
};

int main()
{
  int N = 8;
  int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
  Solution obj;
  cout << obj.cutRod(price, N) << endl;
  return 0;
}