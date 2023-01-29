#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int a, int b)
  {
    return ((a & b) != a) + ((a & b) != b);
  }
};

int main()
{

  Solution ob;
  int a = 5, b = 12;
  cout << ob.solve(a, b) << endl;
  return 0;
}