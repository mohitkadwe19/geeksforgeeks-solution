#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int minOperations(int n)
  {
    long long int ans = 0;
    if (n % 2 == 0)
    {
      n /= 2;
      ans = n * 1ll * n;
    }
    else
    {
      n = (n - 1) / 2;
      ans = n * 1ll * (n + 1);
    }
    return ans;
  }
};

int main()
{
  int N = 3;
  Solution ob;
  cout << ob.minOperations(N) << endl;
  return 0;
}