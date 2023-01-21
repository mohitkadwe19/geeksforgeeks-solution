#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minVal(int a, int b)
  {
    int csb = 0, csa = 0;
    for (int i = 0; i < 31; i++)
    {
      if (b & (1 << i))
      {
        csb++;
      }
      if (a & (1 << i))
      {
        csa++;
      }
    }
    int ans = 0;
    if (csb < csa)
    {
      for (int i = 31; i >= 0; i--)
      {
        if (a & (1 << i))
        {
          ans += (1 << i);
          csb--;
        }
        if (csb == 0)
          break;
      }
      return ans;
    }
    else if (csb == csa)
    {
      return a;
    }
    else
    {
      map<int, int> m;
      for (int i = 0; i < 31; i++)
      {
        if (a & (1 << i))
        {
          m[i]++;
        }
      }
      int len = csb - csa;
      ans = a;
      for (int i = 0; i < 31; i++)
      {
        if (m[i] == 0)
        {
          len--;
          ans += (1 << i);
        }
        if (len == 0)
        {
          break;
        }
      }
      return ans;
    }

    return 0;
  }
};

int main()
{
  Solution sol;
  int A = 3, B = 5;
  cout << sol.minVal(A, B) << endl;
  return 0;
}