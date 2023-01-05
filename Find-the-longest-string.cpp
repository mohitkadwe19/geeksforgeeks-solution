#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string longestString(vector<string> &words)
  {
    sort(words.begin(), words.end());

    unordered_map<string, int> mp;

    for (auto it : words)
    {
      if (mp.find(it) == mp.end())
      {
        mp[it] = 1;
      }
    }
    int maxi = -1e9;
    string ans;
    for (auto it : words)
    {
      string temp;
      int c = 0, n = it.size();

      for (int j = 0; j < n; j++)
      {
        temp += it[j];
        if (mp[temp])
        {
          c++;
        }
      }
      if (c == n && n > maxi)
      {
        maxi = n;
        ans = temp;
      }
    }

    return ans;
  }
};

int main()
{
  vector<string> words = {"ab ", "a", "abc", "abd"};
  Solution obj;
  cout << obj.longestString(words) << endl;
  return 0;
}