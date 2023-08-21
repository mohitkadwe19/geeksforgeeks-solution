#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(int r, int c, int &count, vector<vector<int>> &matrix, int n, int m)
  {
    for (int i = -1; i <= 1; i++)
    {
      for (int j = -1; j <= 1; j++)
      {
        int nr = r + i, nc = c + j;

        if (nr >= 0 and nc >= 0 and nr < n and nc < m and matrix[nr][nc] == 0)
          count += 1;
      }
    }
  }

  int Count(vector<vector<int>> &matrix)
  {
    int n = matrix.size(), m = matrix[0].size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j])
        {
          int tempCount = 0;
          dfs(i, j, tempCount, matrix, n, m);

          if (tempCount > 0 and tempCount % 2 == 0)
            count++;
        }
      }
    }

    return count;
  }
};

int main()
{
  vector<vector<int>> matrix = {{1, 0, 0},
                                {1, 1, 0},
                                {0, 1, 0}};
  Solution obj;
  cout << obj.Count(matrix) << endl;
  return 0;
}