#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long findNumber(long long N)
  {
    if (N == 0 || N == 5)
    {
      return 9;
    }
    else if (N == 1)
    {
      return 1;
    }
    else if (N == 2)
    {
      return 3;
    }
    else if (N == 3)
    {
      return 5;
    }
    else if (N == 4)
    {
      return 7;
    }
    else
    {
      if (N % 5 == 0)
        return (10 * findNumber((N / 5) - 1) + 9);
      return (10 * findNumber(N / 5) + findNumber(N % 5));
    }
  }
};

int main()
{
  int N = 3;
  Solution ob;
  cout << ob.findNumber(N) << endl;
  return 0;
}