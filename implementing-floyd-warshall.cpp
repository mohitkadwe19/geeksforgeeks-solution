#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void shortest_distance(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == -1)
          matrix[i][j] = INT_MAX;
      }
    }

    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {

        for (int j = 0; j < n; j++)
        {

          if (matrix[i][k] != INT_MAX and matrix[k][j] != INT_MAX)
            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == INT_MAX)
          matrix[i][j] = -1;
      }
    }
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> matrix = {{0, 25}, {-1, 0}};
  sol.shortest_distance(matrix);
  return 0;
}