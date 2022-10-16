#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool makePalindrome(int n, vector<string> &arr)
  {
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
      mp[arr[i]]++;
    }
    int count = 0;
    for (auto i : mp)
    {
      if (i.second % 2 != 0)
      {
        count++;
      }
    }
    if (count > 1)
    {
      return false;
    }
    return true;
  }
};

int main()
{
  Solution obj;
  int n = 4;
  vector<string> arr = {"djfh", "gadt", "hfjd", "tdag"};
  cout << obj.makePalindrome(n, arr) << endl;
  return 0;
}