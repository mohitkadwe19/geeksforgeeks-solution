#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution
{

public:
  int getSum(int X, int Y, int Z)
  {
    int mod = 1000000007;

    ll exactSum[X + 1][Y + 1][Z + 1], exactNum[X + 1][Y + 1][Z + 1];

    for (int i = 0; i <= X; i++)

    {

      for (int j = 0; j <= Y; j++)

      {

        for (int k = 0; k <= Z; k++)

        {

          exactSum[i][j][k] = 0;

          exactNum[i][j][k] = 0;
        }
      }
    }

    long long ans = 0;

    exactNum[0][0][0] = 1LL;

    for (int i = 0; i <= X; ++i)

    {

      for (int j = 0; j <= Y; ++j)

      {

        for (int k = 0; k <= Z; ++k)

        {

          if (i > 0)

          {

            exactSum[i][j][k] += (exactSum[i - 1][j][k] * 10 + 4 * exactNum[i - 1][j][k]) % mod;

            exactNum[i][j][k] += exactNum[i - 1][j][k] % mod;
          }

          if (j > 0)

          {

            exactSum[i][j][k] += (exactSum[i][j - 1][k] * 10 + 5 * exactNum[i][j - 1][k]) % mod;

            exactNum[i][j][k] += exactNum[i][j - 1][k] % mod;
          }

          if (k > 0)

          {

            exactSum[i][j][k] += (exactSum[i][j][k - 1] * 10 + 6 * exactNum[i][j][k - 1]) % mod;

            exactNum[i][j][k] += exactNum[i][j][k - 1] % mod;
          }

          ans += exactSum[i][j][k] % mod;

          ans = ans % mod;
        }
      }
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  int X = 1, Y = 1, Z = 1;
  cout << sol.getSum(X, Y, Z) << endl;
  return 0;
}