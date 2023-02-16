#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int goodStones(int n, vector<int> &arr)
  {
    // Code here
    vector<int> vis(n, false), cycle(n, false);
    for (int i = 0; i < n; i++)
    {
      if (vis[i])
        continue;
      unordered_set<int> path;
      int idx;
      for (idx = i; idx >= 0 && idx < n && vis[idx] == false; idx += arr[idx])
      {
        path.insert(idx);
        vis[idx] = true;
      }
      if (idx >= 0 && idx < n)
        if (path.find(idx) != path.end() || cycle[idx] == true)
          for (auto it : path)
            cycle[it] = true;
    }

    return count(cycle.begin(), cycle.end(), false);
  }
};

int main()
{

  vector<int> arr = {2, 3, -1, 2, -2, 4, 1};
  Solution ob;
  cout << ob.goodStones(arr.size(), arr) << endl;

  return 0;
}