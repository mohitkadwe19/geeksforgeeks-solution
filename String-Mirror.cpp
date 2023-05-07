#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string stringMirror(string str)
  {
    string s = "", f;
    s += str[0];
    for (int i = 1; i < str.size(); i++)
    {
      if (s[i - 1] > str[i])
      {
        s += str[i];
      }
      else if (s[i - 1] == str[i])
      {
        if (s.size() == 1)
          break;
        s += str[i];
      }
      else
        break;
    }
    f += s;
    reverse(s.begin(), s.end());
    f += s;
    return f;
  }
};

int main()
{
  string str = "bvdfndkn";
  Solution ob;
  cout << ob.stringMirror(str) << endl;
  return 0;
}