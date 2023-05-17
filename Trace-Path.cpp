#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int isPossible(int n, int m, string s)
  {
    int i = 0, j = 0, mini = 0, minj = 0, maxj = 0, maxi = 0;
    for (auto ch : s)
    {
      if (ch == 'L')
      {
        j--;
      }
      else if (ch == 'R')
      {
        j++;
      }
      else if (ch == 'D')
      {
        i--;
      }
      else if (ch == 'U')
      {
        i++;
      }
      mini = min(mini, i), maxi = max(maxi, i), minj = min(minj, j), maxj = max(maxj, j);
    }
    if ((n - maxi) + mini > 0 and ((m - maxj) + minj) > 0)
    {
      return 1;
    }
    return 0;
  }
};

int main()
{
  int n = 2, m = 3;
  string s = "LLRU";
  Solution ob;
  cout << ob.isPossible(n, m, s) << endl;
  return 0;
}