#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int mod = 1e9 + 7;
  int NthTerm(int n)
  {
    if (n == 1)
    {
      return 2;
    }
    return ((((NthTerm(n - 1) % mod) * n) % mod) + 1) % mod;
  }
};

int main()
{
  Solution sol;
  int n = 4;
  cout << sol.NthTerm(n) << endl;
  return 0;
}