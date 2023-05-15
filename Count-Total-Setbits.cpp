#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long countBits(long long N)
  {
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
      ans += __builtin_popcount(i);
    }
    return ans;
  }
};

int main()
{
  int N = 3;
  Solution ob;
  cout << ob.countBits(N) << endl;
  return 0;
}