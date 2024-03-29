#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0
#define N 9

class Solution
{
public:
  // Function to find a solved Sudoku.
  bool isvalid(int grid[N][N], int row, int col, int val)
  {
    for (int i = 0; i < 9; i++)
    {
      if (grid[i][col] == val)
        return false;
      if (grid[row][i] == val)
        return false;
      if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        return false;
    }
    return true;
  }

  bool SolveSudoku(int grid[N][N])
  {
    // Your code here
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (grid[i][j] == 0)
        {
          for (int val = 1; val <= 9; val++)
          {
            if (isvalid(grid, i, j, val))
            {
              grid[i][j] = val;
              if (SolveSudoku(grid) == true)
                return true;
              else
                grid[i][j] = 0;
            }
          }
          return false;
        }
      }
    }
    return true;
  }

  // Function to print grids of the Sudoku.
  void printGrid(int grid[N][N])
  {
    // Your code here
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cout << grid[i][j] << " ";
      }
      // cout<<endl;
    }
  }
};

int main()
{
  int grid[N][N] = {
      {3, 0, 6, 5, 0, 8, 4, 0, 0},
      {5, 2, 0, 0, 0, 0, 0, 0, 0},
      {0, 8, 7, 0, 0, 0, 0, 3, 1},
      {0, 0, 3, 0, 1, 0, 0, 8, 0},
  };
  Solution ob;
  if (ob.SolveSudoku(grid) == true)
    ob.printGrid(grid);
  else
    cout << "No solution exists";

  cout << endl;
  return 0;
}