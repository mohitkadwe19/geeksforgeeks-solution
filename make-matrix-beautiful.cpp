#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMinOpeartion(vector<vector<int>> matrix, int n)
  {
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
      int sum1 = 0;
      int sum2 = 0;
      for (int j = 0; j < n; j++)
      {
        sum1 = sum1 + matrix[i][j];
        sum2 = sum2 + matrix[j][i];
      }
      maxSum = max(maxSum, max(sum1, sum2));
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = 0; j < n; j++)
      {
        sum += matrix[i][j];
      }
      ans = ans + maxSum - sum;
    }
    return ans;
  }
};

int main()
{
  int N = 2;
  vector<vector<int>> matrix = {{1, 1}, {1, 1}};
  Solution obj;
  cout << obj.findMinOpeartion(matrix, N);
  return 0;
}