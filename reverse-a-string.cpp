#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reverseWord(string str)
  {
    string ans = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
      ans += str[i];
    }
    return ans;
  }
};

int main()
{
  string str = "geeks";
  Solution ob;
  cout << ob.reverseWord(str) << endl;
  return 0;
}