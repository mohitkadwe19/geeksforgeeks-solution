#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c)
  {
    vector<vector<int>> ans(n, vector<int>(m, -1));
    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<pair<int, pair<int, int>>> qp;
    int delcol[] = {0, 1, 0, -1};
    int delrow[] = {-1, 0, 1, 0};
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (c[i][j] == 'W')
        {
          ans[i][j] = 0;
          qp.push({0, {i, j}});
          vis[i][j] = 1;
        }
        else if (c[i][j] == 'N' || c[i][j] == '.')
        {
          ans[i][j] = 0;
        }
      }
    }
    while (!qp.empty())
    {
      int dist = qp.front().first;
      int row = qp.front().second.first;
      int col = qp.front().second.second;
      qp.pop();
      for (int i = 0; i < 4; i++)
      {
        int nrow = row + delrow[i], ncol = col + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == -1 && c[nrow][ncol] == 'H')
        {
          qp.push({dist + 2, {nrow, ncol}});
          ans[nrow][ncol] = dist + 2;
          vis[nrow][ncol] = 1;
        }
        else if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == -1 && c[nrow][ncol] == '.')
        {
          qp.push({dist + 2, {nrow, ncol}});
          vis[nrow][ncol] = 1;
        }
      }
    }
    return ans;
  }
};

int main()
{
  int n = 3, m = 3;
  vector<vector<char>> c = {{'1', '0', '1'}, {'1', '0', '1'}, {'1', '9', '1'}};
  Solution ob;
  vector<vector<int>> ans = ob.chefAndWells(n, m, c);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "\n";
  }
  return 0;
}