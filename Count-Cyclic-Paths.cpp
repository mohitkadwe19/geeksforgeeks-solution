#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countPaths(int N)
  {
    if (N == 1)
    {
      return 0;
    }

    long long int a = 3;

    if (N == 2)
    {
      return 3;
    }
    for (int i = 3; i <= N; i++)
    {
      if (i & 1)
      {
        a = (a * 3) % 1000000007 - 3;
      }
      else
      {
        a = (a * 3) % 1000000007 + 3;
      }
    }
    return a % 1000000007;
  }
};

int main()
{

  int N = 1;
  Solution ob;
  cout << ob.countPaths(N) << endl;
  return 0;
}