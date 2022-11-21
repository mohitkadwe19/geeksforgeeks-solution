#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> UniquePartitions(int n)
  {
    vector<vector<int>> ans;

    vector<int> b;

    dfs(n, ans, b);

    return ans;
  }

  void dfs(int n, vector<vector<int>> &ans, vector<int> &b)
  {

    if (n == 0)
    {

      ans.push_back(b);
      ;

      return;
    }

    for (int i = 0; i < n; i++)
    {

      if (b.empty() || (n - i) <= b.back())
      {

        b.push_back(n - i);

        dfs(i, ans, b);

        b.pop_back();
      }
    }
  }
};

int main()
{
  Solution sol;
  int n = 3;
  vector<vector<int>> ans = sol.UniquePartitions(n);
  for (auto i : ans)
  {
    for (auto j : i)
      cout << j << " ";
    cout << endl;
  }
  return 0;
}