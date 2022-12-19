#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumCost(vector<vector<int>> &f, int n, int k)
  {
    vector<vector<int>> adj[n + 1];
    for (auto &it : f)
    {
      adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, int>> pq;
    pq.push({0, k});

    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
      d[i] = 1e9;
    d[k] = 0;

    while (pq.size())
    {
      auto it = pq.front();
      int x = it.first;
      int y = it.second;
      pq.pop();

      for (auto &it : adj[y])
      {
        if (d[it[0]] > it[1] + x)
        {
          d[it[0]] = it[1] + x;
          pq.push({d[it[0]], it[0]});
        }
      }
    }
    int mx = 0;
    for (int &x : d)
    {
      if (x == 1e9)
      {
        return -1;
      }
      mx = max(mx, x);
    }
    return mx;
  }
};

int main()
{
  Solution sol;
  int n = 4, k = 2;
  vector<vector<int>> flights = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  cout << sol.minimumCost(flights, n, k) << endl;
  return 0;
}