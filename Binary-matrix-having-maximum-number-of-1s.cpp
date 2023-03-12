#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findMaxRow(vector<vector<int>> mat, int N)
  {
    int max = 0, count = 0, index = 0;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (mat[i][j] == 1)
        {
          count++;
        }
      }
      if (count > max)
      {
        max = count;
        index = i;
      }
      count = 0;
    }
    vector<int> ans;
    ans.push_back(index);
    ans.push_back(max);
    return ans;
  }
};

int main()
{
  int N = 3;
  vector<vector<int>> mat = {{0, 1, 1}, {0, 0, 1}, {1, 1, 1}};
  Solution ob;
  vector<int> ans = ob.findMaxRow(mat, N);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}