#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool f1 = false;

  bool f2 = false;

  int dx[4] = {1, -1, 0, 0};

  int dy[4] = {0, 0, 1, -1};

  void dfs(int x, int y, vector<vector<int>> &mat, int n, int m, vector<vector<int>> &vis)
  {
    if (x == 0 || y == 0)

    {

      f1 = true;
    }

    if (x == n - 1 || y == m - 1)

    {

      f2 = true;
    }

    if (f1 && f2)
      return;

    vis[x][y] = 1;

    for (int i = 0; i < 4; i++)

    {

      int nx = x + dx[i];

      int ny = y + dy[i];

      if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] <= mat[x][y] && !vis[nx][ny])

      {

        dfs(nx, ny, mat, n, m, vis);
      }
    }

    vis[x][y] = 0;
  }

  int water_flow(vector<vector<int>> &mat, int n, int m)

  {

    // Write your code here.

    int ans = 0;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)

    {

      for (int j = 0; j < m; j++)

      {

        dfs(i, j, mat, n, m, vis);

        if (f1 && f2)
          ans++;

        f1 = false;

        f2 = false;
      }
    }

    return ans;
  }
};

int main()
{
  int N = 5, M = 5;
  vector<vector<int>> mat = {{1, 3, 3, 2, 4},
                             {4, 5, 6, 4, 4},
                             {2, 4, 5, 3, 1},
                             {6, 7, 1, 4, 5},
                             {6, 1, 1, 3, 4}};
  Solution obj;
  cout << obj.water_flow(mat, N, M) << endl;
  return 0;
}