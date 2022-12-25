#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int MissingNo(vector<vector<int>> &matrix)
  {
    long long int n = matrix.size();
    long long int r = -1, c = -1;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
          r = i;
          c = j;
          break;
        }
      }
      if (r != -1)
      {
        break;
      }
    }
    long long int tr = 0;
    while (tr == r && tr < n)
    {
      tr++;
    }
    long long int sum = 0;

    for (int j = 0; j < n; j++)
    {
      sum += matrix[tr][j];
    }

    long long int tmp = sum;
    for (int i = 0; i < n; i++)
    {
      sum -= matrix[r][i];
    }
    long long int ch = sum;

    for (int i = 0; i < n; i++)
    {
      long long int tt = 0;
      for (int j = 0; j < n; j++)
        if (i == r && j == c)
        {
          tt += ch;
        }
        else
        {
          tt += matrix[i][j];
        }
      if (tt != tmp)
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
      long long int tt = 0;
      for (int j = 0; j < n; j++)
      {
        if (i == c && j == r)
        {
          tt += ch;
        }
        else
        {
          tt += matrix[j][i];
        }
      }
      if (tt != tmp)
      {
        return -1;
      }
    }

    long long int tt = 0;
    for (int i = 0; i < n; i++)
      if (i == r && i == c)
        tt += ch;
      else
        tt += matrix[i][i];

    if (tt != tmp)
    {
      return -1;
    }

    tt = 0;
    for (int i = 0; i < n; i++)
      if (n - i - 1 == r && i == c)
      {
        tt += ch;
      }
      else
        tt += matrix[n - i - 1][i];

    if (tt != tmp)
    {
      return -1;
    }

    return ch <= 0 ? -1 : ch;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> matrix = {{5, 5}, {5, 0}};
  cout << sol.MissingNo(matrix) << endl;
  return 0;
}