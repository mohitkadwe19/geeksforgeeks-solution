#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int a, int b, int c)
  {
    if (2 * (a + b + 1) < c || 2 * (b + c + 1) < a || 2 * (c + a + 1) < b)
    {
      return -1;
    }
    return (a + b + c);
  }
};

int main()
{
  int a = 3, b = 3, c = 3;
  Solution ob;
  cout << ob.solve(a, b, c) << endl;
  return 0;
}