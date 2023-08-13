#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int nthFibonacci(int n)
  {
    if (n == 0)
      return 0;

    int a = 0, b = 1;
    int mod = (int)1e9 + 7;
    n -= 2;
    while (n-- >= 0)
    {
      int c = (a % mod + b % mod) % mod;
      a = b;
      b = c;
    }
    return b;
  }
};

int main()
{
  Solution ob;
  cout << ob.nthFibonacci(5) << endl;
  return 0;
}