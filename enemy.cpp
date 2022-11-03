#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int largestArea(int n, int m, int k, vector<vector<int>> &enemy)
  {
    vector<int> row(n, 0);

    vector<int> col(m, 0);

    for (int i = 0; i < enemy.size(); i++)
    {

      row[enemy[i][0] - 1] = -1;

      col[enemy[i][1] - 1] = -1;
    }

    int rowMax = 0;

    int colMax = 0;

    int i = 0;

    int j = 0;

    while (j < n)
    {

      if (row[j] != -1)
      {

        j++;

        rowMax = max(rowMax, j - i);
      }
      else if (row[j] == -1)
      {

        j++;

        i = j;
      }
    }

    i = 0;

    j = 0;

    while (j < m)
    {

      if (col[j] != -1)
      {

        j++;

        colMax = max(colMax, j - i);
      }
      else if (col[j] == -1)
      {

        j++;

        i = j;
      }
    }

    return rowMax * colMax;
  }
};

int main()
{
  Solution sol;
  int n = 2, m = 2, k = 1;
  vector<vector<int>> enemy = {{1, 1}, {1, 1}};
  cout << sol.largestArea(n, m, k, enemy) << endl;
  return 0;
}