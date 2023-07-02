#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int setSetBit(int x, int y, int l, int r)
  {
    for (int i = r - 1; i >= l - 1; i--)
    {
      int bit_y = (y & (1 << i)) ? 1 : 0;

      if (bit_y)
      {
        x = x | (1 << i);
      }
    }
    return x;
  }
};

int main()
{
  int X = 44, Y = 3, L = 1, R = 5;
  Solution ob;
  cout << ob.setSetBit(X, Y, L, R) << endl;
  return 0;
}