#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution
{
public:
  int fillingBucket(int N)
  {
    int a = 1, b = 2, c = 0, mod = 1e8;

    if (N <= 2)
    {
      return N;
    }

    for (int i = 2; i < N; i++)
    {

      c = (a + b) % mod;

      a = b;

      b = c;
    }

    return c;
  }
};

int main()
{
  Solution sol;
  int N = 8223;
  cout << sol.fillingBucket(N) << endl;
  return 0;
}