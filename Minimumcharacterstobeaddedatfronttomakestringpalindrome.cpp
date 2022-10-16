#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minChar(string str)
  {
    int l = 0;
    int r = str.length() - 1;
    int len = str.length();
    int count = 0;
    while (l < r)
    {
      if (str[l] == str[r])
      {
        l++;
        r--;
      }
      else
      {
        count = len - r;
        l = 0;
        while (str[l] == str[r])
        {
          count--;
          l++;
        }
        r--;
      }
    }
    return count;
  }
};

int main()
{
  Solution s;
  string str = "aacecaaa";
  cout << s.minChar(str) << endl;
  return 0;
}