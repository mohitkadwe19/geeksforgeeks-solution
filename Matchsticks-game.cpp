#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int matchGame(long long N)
  {
    if (N % 5 == 0)
    {
      return -1;
    }
    return N % 5;
  }
};

int main()
{
  long long N = 48;
  Solution ob;
  cout << ob.matchGame(N) << endl;
  return 0;
}