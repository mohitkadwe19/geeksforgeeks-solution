#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool makePalindrome(int n, vector<string> &arr)
  {
    int siz = arr[0].size();
    unordered_map<string, int> ump;
    for (auto x : arr)
    {
      ump[x]++;
    }
    for (int i = 0; i < n; i++)
    {
      string str = arr[i];
      string s = str;
      reverse(s.begin(), s.end());
      if (ump[s] != 0)
      {
        if (s != str)
        {
          ump[s]--;
          ump[str]--;
        }
        else if (s == str)
        {
          ump[s] = ump[s] % 2;
        }
      }
    }
    int cnt = 0;
    for (auto x : ump)
    {
      string str = x.first;
      string s = str;
      reverse(s.begin(), s.end());
      if (x.second > 0)
      {
        if (s == str && x.second == 1)
        {
          cnt++;
        }
        else
        {
          return false;
        }
      }
    }
    if (cnt < 2)
    {
      return true;
    }
    return false;
  }
};

int main()
{
  int n = 4;
  vector<string> arr = {"djfh", "gadt", "hfjd", "tdag"};
  Solution ob;
  cout << ob.makePalindrome(n, arr) << endl;
  return 0;
}