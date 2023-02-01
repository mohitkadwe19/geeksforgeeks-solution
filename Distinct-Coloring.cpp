#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int distinctColoring(int N, int r[], int g[], int b[])
  {
    long long int dp[N][3];
    dp[0][0] = r[0];
    dp[0][1] = g[0];
    dp[0][2] = b[0];

    for (int i = 1; i < N; i++)
    {
      dp[i][0] = r[i] + min(dp[i - 1][1], dp[i - 1][2]);
      dp[i][1] = g[i] + min(dp[i - 1][0], dp[i - 1][2]);
      dp[i][2] = b[i] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    return min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
  }
};

int main()
{
  int N = 3, r[] = {1, 1, 1}, g[] = {2, 2, 2}, b[] = {3, 3, 3};
  Solution ob;
  cout << ob.distinctColoring(N, r, g, b) << endl;

  return 0;
}