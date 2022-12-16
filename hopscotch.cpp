#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
  {

    int ans = 0;
    if (ty == 0)
    {
      if (j % 2 != 0)
      {
        if (i - 1 >= 0)
          ans += mat[i - 1][j];
        if (j - 1 >= 0)
          ans += mat[i][j - 1];
        if (j + 1 < m)
          ans += mat[i][j + 1];
        if (i + 1 < n)
          ans += mat[i + 1][j];
        if (i + 1 < n && j - 1 >= 0)
          ans += mat[i + 1][j - 1];
        if (i + 1 < n && j + 1 < m)
          ans += mat[i + 1][j + 1];
      }
      else if (j % 2 == 0)
      {
        if (i - 1 >= 0)
          ans += mat[i - 1][j];
        if (j - 1 >= 0)
          ans += mat[i][j - 1];
        if (j + 1 < m)
          ans += mat[i][j + 1];
        if (i + 1 < n)
          ans += mat[i + 1][j];
        if (i - 1 >= 0 && j - 1 >= 0)
          ans += mat[i - 1][j - 1];
        if (i - 1 >= 0 && j + 1 < m)
          ans += mat[i - 1][j + 1];
      }
    }
    else if (ty == 1)
    {
      if (j % 2 != 0)
      {
        if (i - 2 >= 0)
          ans += mat[i - 2][j];
        if (j - 2 >= 0)
          ans += mat[i][j - 2];
        if (j + 2 < m)
          ans += mat[i][j + 2];
        if (i + 2 < n)
          ans += mat[i + 2][j];

        if (i + 2 < n && j - 1 >= 0)
          ans += mat[i + 2][j - 1];
        if (i + 1 < n && j - 2 >= 0)
          ans += mat[i + 1][j - 2];

        if (i + 2 < n && j + 1 < m)
          ans += mat[i + 2][j + 1];
        if (i - 1 >= 0 && j - 2 >= 0)
          ans += mat[i - 1][j - 2];

        if (i - 1 >= 0 && j + 2 < m)
          ans += mat[i - 1][j + 2];
        if (i + 1 < n && j + 2 < m)
          ans += mat[i + 1][j + 2];

        if (i - 1 >= 0 && j - 1 >= 0)
          ans += mat[i - 1][j - 1];
        if (i - 1 >= 0 && j + 1 < m)
          ans += mat[i - 1][j + 1];
      }
      else if (j % 2 == 0)
      {
        if (i - 2 >= 0)
          ans += mat[i - 2][j];
        if (j - 2 >= 0)
          ans += mat[i][j - 2];
        if (j + 2 < m)
          ans += mat[i][j + 2];
        if (i + 2 < n)
          ans += mat[i + 2][j];

        if (i + 1 < n && j + 2 < m)
          ans += mat[i + 1][j + 2];
        if (i + 1 < n && j - 2 >= 0)
          ans += mat[i + 1][j - 2];

        if (i - 1 >= 0 && j - 2 >= 0)
          ans += mat[i - 1][j - 2];
        if (i - 2 >= 0 && j - 1 >= 0)
          ans += mat[i - 2][j - 1];

        if (i - 2 >= 0 && j + 1 < m)
          ans += mat[i - 2][j + 1];
        if (i - 1 >= 0 && j + 2 < m)
          ans += mat[i - 1][j + 2];

        if (i + 1 < n && j - 1 >= 0)
          ans += mat[i + 1][j - 1];
        if (i + 1 < n && j + 1 < m)
          ans += mat[i + 1][j + 1];
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  int n = 3, m = 3;
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int ty = 1, i = 0, j = 0;
  cout << sol.hopscotch(n, m, mat, ty, i, j) << endl;
  return 0;
}