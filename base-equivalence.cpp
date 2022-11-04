#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string baseEquiv(int n, int m)
  {
    for (int i = 2; i <= 32; i++)
    {

      int temp = (int)(log(n) / log(i));

      if (temp + 1 == m)

        return "Yes";
    }

    return "No";
  }
};

int main()
{
  Solution sol;
  int n = 8, m = 2;
  cout << sol.baseEquiv(n, m) << endl;
  return 0;
}