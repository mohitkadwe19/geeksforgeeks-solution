#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int row[4] = {0, -1, 0, 1}, col[4] = {-1, 0, 1, 0};

  bool exist(int x, int y, int n, int m, vector<vector<int>> &copy)
  {
    return (x >= 0 && y >= 0 && x < n && y < m && copy[x][y] == 1);
  }

  void dfs(int x, int y, int n, int m, vector<vector<int>> &island)
  {
    island[x][y] = 0;
    for (int k = 0; k < 4; k++)
    {
      int x_ = x + row[k], y_ = y + col[k];
      if (exist(x_, y_, n, m, island))
        dfs(x_, y_, n, m, island);
    }
  }

  vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
  {
    // code here
    vector<vector<int>> island(n, vector<int>(m, 0));
    vector<int> res;
    int k = operators.size();

    for (int ind = 0; ind < k; ind++)
    {
      int x = operators[ind][0], y = operators[ind][1], cnt = 0;
      island[x][y] = 1;
      vector<vector<int>> copy = island;

      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          if (copy[i][j] == 1)
            cnt++, dfs(i, j, n, m, copy);
        }
      }
      res.push_back(cnt);
    }

    return res;
  }
};

int main()
{
  Solution obj;
  int n = 4, m = 5, k = 4;
  vector<vector<int>> A = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};
  vector<int> ans = obj.numOfIslands(n, m, A);
  for (auto i : ans)
    cout << i << " ";
  return 0;
}