#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  const int mod = 1000000007;

  long long countWays(int n)
  {

    vector<long long> v(n + 1);
    v[0] = 1;
    if (n >= 1)
    {
      v[1] = 1;
      if (n >= 2)
      {
        v[2] = 2;
        if (n >= 3)
        {
          v[3] = 4;
        }
      }
    }

    for (int i = 4; i <= n; i++)
    {
      v[i] = (v[i - 1] + v[i - 2] + v[i - 3]) % mod;
    }
    return v[n];
  }
};

int main()
{
  int N = 1;
  Solution obj;
  cout << obj.countWays(N) << endl;
  return 0;
}