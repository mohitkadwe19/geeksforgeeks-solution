#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isFrequencyUnique(int n, int arr[])
  {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      mp[arr[i]]++;
    }

    set<int> s;
    for (auto it : mp)
    {
      if (s.count(it.second) == 0)
      {
        s.insert(it.second);
      }
      else
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  int N = 5;
  int arr[] = {1, 1, 2, 5, 5};
  Solution ob;
  cout << ob.isFrequencyUnique(N, arr) << endl;
  return 0;
}