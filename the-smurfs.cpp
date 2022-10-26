#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMin(int n, char a[])
  {
    int r = 0, g = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
      if (a[i] == 'R')
      {
        r++;
      }
      else if (a[i] == 'G')
      {
        g++;
      }
      else if (a[i] == 'B')
      {
        b++;
      }
    }

    if (r == n || g == n || b == n)
    {
      return n;
    }
    else if (r % 2 == 0 && g % 2 == 0 && b % 2 == 0)
    {
      return 2;
    }
    else if (r % 2 != 0 && g % 2 != 0 && b % 2 != 0)
    {
      return 2;
    }
    else
    {
      return 1;
    }
  }
};

int main()
{
  Solution sol;
  int n = 5;
  char a[n] = {'R', 'G', 'B', 'R', 'B'};
  cout << sol.findMin(n, a) << endl;
  return 0;
}