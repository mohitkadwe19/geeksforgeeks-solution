#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find distance of nearest 1 in the grid for each cell.
  vector<vector<int>> nearest(vector<vector<int>> grid)
  {
    // Code here
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    queue<pair<int, int>> dq;
    pair<int, int> p1;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
        {
          p1.first = i;
          p1.second = j;
          dq.push(p1);
          ans[i][j] = 0;
        }
        else
        {
          ans[i][j] = -1;
        }
      }
    }

    while (dq.size() > 0)
    {
      int s = dq.size();
      while (s-- > 0)
      {
        pair<int, int> p = dq.front();
        dq.pop();
        int i = p.first, j = p.second;
        if (isValid(i + 1, j, n, m, ans))
        {
          p1.first = i + 1;
          p1.second = j;
          dq.push(p1);
          ans[i + 1][j] = ans[i][j] + 1;
        }
        if (isValid(i, j + 1, n, m, ans))
        {
          p1.first = i;
          p1.second = j + 1;
          dq.push(p1);
          ans[i][j + 1] = ans[i][j] + 1;
        }
        if (isValid(i - 1, j, n, m, ans))
        {
          p1.first = i - 1;
          p1.second = j;
          dq.push(p1);
          ans[i - 1][j] = ans[i][j] + 1;
        }
        if (isValid(i, j - 1, n, m, ans))
        {
          p1.first = i;
          p1.second = j - 1;
          dq.push(p1);
          ans[i][j - 1] = ans[i][j] + 1;
        }
      }
    }
    return ans;
  }

  bool isValid(int i, int j, int n, int m, vector<vector<int>> &ans)
  {
    if (i < 0 || j < 0 || i >= n || j >= m || ans[i][j] != -1)
      return false;
    return true;
  }
};

int main()
{
  Solution sol;
  int[][] grid = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int res = sol.nearest(grid);
  for (int i = 0; i < grid.length; i++)
  {
    for (int j = 0; j < grid[0].length; j++)
    {

      cout << res[i][j] << " ";
    }
  }
}