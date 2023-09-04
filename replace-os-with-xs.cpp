#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(int row, int col, vector<vector<char>> &grid, int n, int m, char symbol)
  {
    if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != 'O')
      return;

    grid[row][col] = symbol;
    dfs(row + 1, col, grid, n, m, symbol);
    dfs(row, col + 1, grid, n, m, symbol);
    dfs(row - 1, col, grid, n, m, symbol);
    dfs(row, col - 1, grid, n, m, symbol);
  }
  vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
        {
          if (mat[i][j] == 'O')
          {
            dfs(i, j, mat, n, m, '$');
          }
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (mat[i][j] == 'O')
        {
          dfs(i, j, mat, n, m, 'X');
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (mat[i][j] == '$')
          mat[i][j] = 'O';
      }
    }
    return mat;
  }
};

int main()
{
  Solution s;
  int n = 5, m = 4;
  vector<vector<char>> mat = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  vector<vector<char>> ans = s.fill(n, m, mat);
  for (auto i : ans)
  {
    for (auto j : i)
      cout << j << " ";
    cout << endl;
  }
  return 0;
}