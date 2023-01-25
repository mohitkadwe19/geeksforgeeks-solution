#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minOperation(string s)
  {
    for (int i = s.size() / 2 - 1; i >= 0; i--)
    {
      if (s.substr(0, i + 1) == s.substr(i + 1, i + 1))
      {
        return (i + 1) + 1 + s.size() - 2 * (i + 1);
      }
    }

    return s.size();
  }
};

int main()
{
  Solution sol;
  string s = "abcabca";
  cout << sol.minOperation(s) << endl;
  return 0;
}