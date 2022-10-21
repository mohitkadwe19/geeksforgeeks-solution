#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
  vector<int> reverseSpiral(int R, int C, vector<vector<int>> &a)
  {
    vector<int> reverseSpiralTraversal = {};
    // reverse order of spiral traversal
    int top = 0, bottom = R - 1, left = 0, right = C - 1;
    while (top <= bottom && left <= right)
    {
      for (int i = left; i <= right; i++)
      {
        reverseSpiralTraversal.push_back(a[top][i]);
      }
      top++;

      if (top <= bottom && left <= right)
      {
      }
      else
        break;

      for (int i = top; i <= bottom; i++)
      {
        reverseSpiralTraversal.push_back(a[i][right]);
      }
      right--;

      if (top <= bottom && left <= right)
      {
      }
      else
        break;

      for (int i = right; i >= left; i--)
      {
        reverseSpiralTraversal.push_back(a[bottom][i]);
      }
      bottom--;

      if (top <= bottom && left <= right)
      {
      }
      else
        break;

      for (int i = bottom; i >= top; i--)
      {
        reverseSpiralTraversal.push_back(a[i][left]);
      }
      left++;
    }
    reverse(reverseSpiralTraversal.begin(), reverseSpiralTraversal.end());
    return reverseSpiralTraversal;
  }
};

int main()
{
  Solution sol;
  int R = 3, C = 3;
  vector<vector<int>> a = {{9, 8, 7},
                           {6, 5, 4},
                           {3, 2, 1}};
  vector<int> reverseSpiralTraversal = sol.reverseSpiral(R, C, a);
  for (int i = 0; i < reverseSpiralTraversal.size(); i++)
  {
    cout << reverseSpiralTraversal[i] << " ";
  }
  return 0;
}