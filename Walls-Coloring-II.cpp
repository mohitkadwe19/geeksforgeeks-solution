#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minCost(vector<vector<int>> &costs)
  {
    int n = costs.size();
    int m = costs[0].size();
    if (m == 1 and n > 1)
      return -1;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<int> prev(m, 0);
    for (int i = n - 1; i >= 0; i--)
    {
      priority_queue<int, vector<int>, greater<int>> pq;
      for (int j = 0; j < m; j++)
      {
        pq.push(prev[j]);
      }
      for (int j = 0; j < m; j++)
      {
        bool flag = true;
        if (pq.top() == prev[j]) // If the top element is equal to prev[j] then it is useful to remove it otherwise it will show no effect
        {
          pq.pop();
          flag = !flag;
        }
        dp[i][j] = costs[i][j] + pq.top();
        if (!flag)
          pq.push(prev[j]);
      }
      prev = dp[i];
    }
    return *min_element(dp[0].begin(), dp[0].end());
  }
};

int main()
{
  int N = 4, K = 3;
  vector<vector<int>> costs = {{1, 5, 7},
                               {5, 8, 4},
                               {3, 2, 9},
                               {1, 2, 4}};

  Solution obj;
  cout << obj.minCost(costs) << endl;
  return 0;
}