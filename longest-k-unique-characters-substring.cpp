#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestKSubstr(string s, int k)
  {
    map<char, int> hashMap;
    int n = s.length();
    int i = 0, j = 0, x = k;
    int maxlen = -1;
    while (i < n && j < n)
    {
      while (x >= 0 && j < n)
      {
        if (hashMap.find(s[j]) == hashMap.end())
          x--;
        hashMap[s[j]]++;
        if (x == -1)
          maxlen = max(maxlen, j - i);
        j++;
      }
      while (x == -1)
      {
        hashMap[s[i]]--;
        if (hashMap[s[i]] == 0)
        {
          hashMap.erase(s[i]);
          x++;
        }
        i++;
      }
    }
    if (x == 0)
      maxlen = max(maxlen, j - i);
    return maxlen;
  }
};

int main()
{
  string S = "aabacbebebe";
  int k = 3;
  Solution obj;
  cout << obj.longestKSubstr(S, k) << endl;
  return 0;
}