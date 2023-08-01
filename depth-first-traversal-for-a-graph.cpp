#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to return a list containing the DFS traversal of the graph.
  vector<int> ans;
  void solve(vector<int> adj[], vector<int> &vis, int start)
  {
    for (auto it : adj[start])
    {
      if (vis[it] == 0)
      {
        // cout<<it<<" ";
        vis[it] = 1;
        ans.push_back(it);
        solve(adj, vis, it);
      }
    }
  }
  vector<int> dfsOfGraph(int V, vector<int> adj[])
  {
    // Code here
    vector<int> vis(V, 0);
    ans.push_back(0);
    vis[0] = 1;
    solve(adj, vis, 0);
    return ans;
  }
};

int main()
{
  Solution sol;
  int V = 5;
  vector<int> adj[V];
  adj[0].push_back(1);
  adj[0].push_back(4);
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(3);
  adj[3].push_back(4);
  adj[4].push_back(0);
  adj[4].push_back(1);

  vector<int> ans = sol.dfsOfGraph(V, adj);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}