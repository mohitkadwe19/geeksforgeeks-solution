#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> vis;
  int count = 0;
  int edges = 0;

  void dfs(int node, vector<vector<int>> adj)
  {
    vis[node] = 1;
    count++;
    edges += adj[node].size();
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        dfs(it, adj);
      }
    }
  }
  int findNumberOfGoodComponent(int V, vector<vector<int>> &adj)
  {
    int ans = 0;
    vis.resize(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
      count = 0;
      edges = 0;
      if (!vis[i])
      {
        dfs(i, adj);
        int temp1 = (count * (count - 1)) / 2;
        if (temp1 == edges / 2)
          ans++;
      }
    }
    return ans;
  }
};

int main()
{

  int V = 3;
  vector<vector<int>> adj = {{0, 1}, {1, 2}, {2, 0}};
  Solution obj;
  cout << obj.findNumberOfGoodComponent(V, adj) << endl;
  return 0;
}