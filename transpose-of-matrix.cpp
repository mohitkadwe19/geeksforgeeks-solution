#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find transpose of a matrix.
  void transpose(vector<vector<int>> &matrix, int n)
  {

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};

int main()
{
  Solution obj;
  int N = 4;
  vector<vector<int>> matrix = {{1, 1, 1, 1},
                                {2, 2, 2, 2},
                                {3, 3, 3, 3},
                                {4, 4, 4, 4}};
  obj.transpose(matrix, N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}