#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  pair<int, int> endPoints(vector<vector<int>> mat, int r, int c)
  {
    int i, j, h = 1, v;

    i = j = v = 0;

    while (i >= 0 && j >= 0 && i < r && j < c)

    {

      if (mat[i][j] != 0)

      {

        mat[i][j] = 0;

        if (h)
          v = h, h = 0;

        else
          h = -v, v = 0;
      }

      i += v, j += h;
    }

    i = min(i, r - 1), i = max(i, 0);

    j = min(j, c - 1), j = max(j, 0);

    return {i, j};
  }
};

int main()
{
  int R = 2, C = 2;
  vector<vector<int>> matrix = {{0, 1},
                                {1, 0}};
  Solution ob;
  pair<int, int> ans = ob.endPoints(matrix, R, C);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}