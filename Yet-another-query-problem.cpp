#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q)
  {
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
      int count = 0;
      for (int j = i; j < N; j++)
      {
        if (A[i] == A[j])
        {
          count++;
        }
      }
      v.push_back(count);
    }
    vector<int> ans;
    int m = Q.size();
    for (int i = 0; i < m; i++)
    {
      int cou = 0;
      for (int j = Q[i][0]; j <= Q[i][1]; j++)
      {
        if (v[j] == Q[i][2])
        {
          cou++;
        }
      }
      ans.push_back(cou);
    }
    return ans;
  }
};

int main()
{
  int N = 5, num = 3;
  vector<int> A = {1, 1, 3, 4, 3};
  vector<vector<int>> Q = {{0, 2, 2}, {0, 2, 1}, {0, 4, 2}};
  Solution s;
  vector<int> ans = s.solveQueries(N, num, A, Q);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}