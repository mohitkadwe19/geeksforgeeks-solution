#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int modulo(string s, int m)
  {
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
      res = res * 2 + (s[i] - '0');
      res %= m;
    }
    return res;
  }
};

int main()
{
  string str = "101";
  int m = 2;
  Solution ob;
  cout << ob.modulo(str, m) << endl;
  return 0;
}