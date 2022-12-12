#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(int node, int parent, int &timer, vector<int> adj[], vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &isArticulation)
  {

    vis[node] = 1;
    tin[node] = low[node] = timer++;

    int child = 0;

    for (auto &it : adj[node])
    {

      if (it == parent)
      {
        continue;
      }

      if (!vis[it])
      {

        dfs(it, node, timer, adj, vis, tin, low, isArticulation);
        low[node] = min(low[node], low[it]);

        if (low[it] >= tin[node] && parent != -1)
        {

          isArticulation[node] = 1;
        }
        child++;
      }
      else
      {

        low[node] = min(low[node], tin[it]);
      }
    }

    if (parent == -1 && child > 1)
    {
      isArticulation[node] = 1;
    }
  }

  vector<int> articulationPoints(int V, vector<int> adj[])
  {
    // Code here

    vector<int> res;
    vector<int> vis(V, 0);
    vector<int> tin(V, -1);
    vector<int> low(V, -1);
    vector<int> isArticulation(V, 0);

    int timer = 0;

    for (int i = 0; i < V; i++)
    {

      if (!vis[i])
      {

        dfs(i, -1, timer, adj, vis, tin, low, isArticulation);
      }
    }

    for (int i = 0; i < V; i++)
    {

      if (isArticulation[i])
      {
        res.push_back(i);
      }
    }

    if (res.size() == 0)
    {
      res.push_back(-1);
    }

    return res;
  }
};

int main()
{
  Solution sol;
  int V = 2;
  vector<int> adj[V];
  adj[0].push_back(1);
  adj[1].push_back(4);
  vector<int> res = sol.articulationPoints(V, adj);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
}