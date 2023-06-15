#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string longestPalin(string S)
  {
    int start = 0, end = 0, len = 0, n = S.length();
    for (int i = 1; i < n; i++)
    {
      int s = i - 1, e = i + 1;
      while (s >= 0 and e < n and S[s] == S[e])
      {
        if (e - s + 1 > len)
        {
          len = e - s + 1;
          start = s;
          end = e;
        }
        s--;
        e++;
      }
      s = i - 1;
      e = i;

      while (s >= 0 and e < n and S[s] == S[e])
      {
        if (e - s + 1 > len)
        {
          len = e - s + 1;
          start = s;
          end = e;
        }
        s--;
        e++;
      }
    }
    string ans = "";
    for (int i = start; i <= end; i++)
      ans += S[i];
    return ans;
  }
};

int main()
{
  string S = "aaaabbaa";
  Solution ob;
  cout << ob.longestPalin(S) << endl;
  return 0;
}