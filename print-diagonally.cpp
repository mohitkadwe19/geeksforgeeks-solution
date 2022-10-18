#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
  vector<int> downwardDigonal(int N, vector<vector<int>> A)
  {
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
      int j = 0;
      int k = i;
      while (k >= 0)
      {
        ans.push_back(A[j][k]);
        j++;
        k--;
      }
    }
    for (int i = 1; i < N; i++)
    {
      int j = i;
      int k = N - 1;
      while (j < N)
      {
        ans.push_back(A[j][k]);
        j++;
        k--;
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  int n = 2;
  vector<vector<int>> arr = {{1, 2}, {3, 4}};
  vector<int> res = sol.downwardDigonal(n, arr);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}