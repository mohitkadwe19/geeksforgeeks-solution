#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool dfs(int n, vector<int> adj[], vector<int> &visited, int src)
  {
    if (n == 0)
    {
      return true;
    }
    visited[src] = 1;
    for (auto &x : adj[src])
    {
      if (visited[x] == 0)
      {
        if (dfs(n - 1, adj, visited, x))
        {
          return true;
        }
      }
    }
    visited[src] = 0;
    return false;
  }
  bool check(int N, int M, vector<vector<int>> Edges)
  {
    vector<int> adj[N];

    for (auto &x : Edges)
    {
      adj[x[0] - 1].push_back(x[1] - 1);
      adj[x[1] - 1].push_back(x[0] - 1);
    }

    vector<int> visited(N, 0);

    for (int i = 0; i < N; i++)
    {
      if (dfs(N - 1, adj, visited, i))
      {
        return true;
      }
    }
    return false;
  }
};

int main()
{
  Solution sol;
  int N = 4, M = 4;
  vector<vector<int>> Edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
  cout << sol.check(N, M, Edges) << endl;
  return 0;
}