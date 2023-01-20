#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxWeightCell(int N, vector<int> Edge)
  {
    vector<int> weight(N, 0);
    for (int i = 0; i < N; i++)
    {
      if (Edge[i] != -1)
      {
        weight[Edge[i]] += i;
      }
    }
    int mx = INT_MIN;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
      if (weight[i] >= mx)
      {
        ans = i;
        mx = weight[i];
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  int N = 4;
  vector<int> Edge = {2, 0, -1, 2};
  cout << sol.maxWeightCell(N, Edge) << endl;
  return 0;
}