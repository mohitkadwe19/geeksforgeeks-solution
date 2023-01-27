#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int CountWays(string str)
  {
    if (str[0] == '0')
    {
      return 0;
    }
    int n = str.length();
    int mod = 1e9 + 7;

    vector<int> dp(n + 1, 1);

    for (int i = n - 1; i >= 0; i--)
    {
      int one = 0, two = 0;
      if (str[i] != '0')
      {
        one = dp[i + 1];
        if (i + 1 < str.length())
        {
          int temp = stoi(str.substr(i, 2));
          if (temp <= 26)
          {
            two = dp[i + 2];
          }
        }
      }
      dp[i] = (one + two * 1LL) % mod;
    }

    return dp[0];
  }
};

int main()
{
  Solution sol;
  string str = "123";
  cout << sol.CountWays(str) << endl;
  return 0;
}