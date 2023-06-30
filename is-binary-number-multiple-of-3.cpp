#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int isDivisible(string s)
  {
    int odd = 0, even = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (i % 2 == 0)
        even += s[i] - '0';
      else
        odd += s[i] - '0';
    }
    return (abs(odd - even) % 3 == 0);
  }
};

int main()
{
  string S = "0011";
  Solution ob;
  cout << ob.isDivisible(S) << endl;
  return 0;
}