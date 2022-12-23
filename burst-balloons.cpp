#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxCoins(int N, vector<int> &arr)
  {
    // code here
    int dp[N][N];
    memset(dp, 0, sizeof(dp));
    for (int gap = 0; gap < N; gap++)
    {
      for (int i = 0, j = gap; j < N; i++, j++)
      {
        int max = INT_MIN;
        for (int k = i; k <= j; k++)
        {
          int left = 1, right = 1;
          if (i != 0)
          {
            left = arr[i - 1];
          }
          if (j != N - 1)
          {
            right = arr[j + 1];
          }
          int before = 0, after = 0;
          if (k != i)
          {
            before = dp[i][k - 1];
          }
          if (k != j)
          {
            after = dp[k + 1][j];
          }
          int temp = left * arr[k] * right + before + after;
          if (temp > max)
          {
            max = temp;
          }
        }
        dp[i][j] = max;
      }
    }
    return dp[0][N - 1];
  }
};

int main()
{

  Solution ob;
  int N = 4, arr[] = {3, 1, 5, 8};
  vector<int> A(arr, arr + N);
  cout << ob.maxCoins(N, A) << endl;
  return 0;
}