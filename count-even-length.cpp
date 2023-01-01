#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int modInverse(int A, int M)
  {
    int m0 = M;
    int y = 0, x = 1;

    if (M == 1)
      return 0;

    while (A > 1)
    {
      // q is quotient
      int q = A / M;
      int t = M;

      // m is remainder now, process same as
      // Euclid's algo
      M = A % M;
      A = t;
      t = y;

      // Update y and x
      y = x - q * y;
      x = t;
    }

    // Make x positive
    if (x < 0)
      x += m0;

    return x;
  }

  int compute_value(int n)
  {
    int mod = 1000000007;
    long ans = 2;
    long prev = 1;
    for (int i = 1; i < n; i++)
    {
      long temp = ((((n + 1 - i) * prev) % mod) * modInverse(i, mod)) % mod;
      prev = temp;
      long t = (temp * temp) % mod;
      ans = (ans + t) % mod;
    }
    return (int)ans % mod;
  }
};

int main()
{

  int n = 363;
  Solution sol;
  cout << sol.compute_value(n) << endl;
  return 0;
}