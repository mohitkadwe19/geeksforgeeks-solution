#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int swapBitGame(long long N)
  {
    int count = 0;

    while (N)
    {
      N = N & N - 1;
      count++;
    }
    if (count % 2 == 0)
      return 2;
    return 1;
  }
};

int main()
{
  Solution sol;
  long long N = 1;
  cout << sol.swapBitGame(N) << endl;
  return 0;
}