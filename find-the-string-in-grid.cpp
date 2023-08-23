#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};

  bool check(int i, int j, int n, int m, vector<vector<char>> grid, int w, int len, string word, int dirx, int diry)
  {
    int i1, j1;

    if (w == len)
      return true;

    if (i < 0 || j < 0 || i >= n || j >= m)
      return false;

    if (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == word[w] && check(i + dirx, j + diry, n, m, grid, w + 1, len, word, dirx, diry))
    {
      return true;
    }

    return false;
  }

  vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
  {
    // Code here
    int n = grid.size();
    int m = grid[0].size(), i1, j1;

    vector<vector<int>> res;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == word[0])
        {
          for (int x = 0; x < 8; x++)
          {
            i1 = i + dir[x].first;
            j1 = j + dir[x].second;

            if (check(i1, j1, n, m, grid, 1, word.length(), word, dir[x].first, dir[x].second))
            {
              res.push_back({i, j});
              break;
            }
          }
        }
      }
    }

    return res;
  }
};

int main()
{
  Solution sol;
  vector<vector<char>> grid = {};
}