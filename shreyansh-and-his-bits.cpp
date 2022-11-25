#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long ncr(int n, int r)
  {

    if (n < r)
      return 0;

    if (r > n - r)
      r = n - r;

    long long dp[r + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {

      for (int j = min(i, r); j > 0; j--)
        dp[j] = (dp[j] + dp[j - 1]);
    }
    return dp[r];
  };
  long long count(long long x)
  {
    vector<long long> str;
    long long copy = x;
    int countSet = 0;
    while (copy > 0)
    {
      if ((copy & 1))
      {
        countSet++;
      }
      str.push_back((copy & 1));
      copy = (copy >> 1);
    }
    reverse(str.begin(), str.end());
    long long ans = 0;

    for (int i = 0; i < str.size(); i++)
    {
      if (str[i] == 1)
      {
        ans += ncr(str.size() - (i + 1), countSet);
        countSet--;
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  long long N = 8;
  cout << sol.count(N) << endl;
  return 0;
}