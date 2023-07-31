#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to return Breadth First Traversal of given graph.
  vector<int> bfsOfGraph(int V, vector<int> adj[])
  {
    // Code here
    vector<int> al;
    queue<int> q;
    vector<bool> vis(V, false);

    q.push(0);     // adding the first node
    vis[0] = true; // mark it visited.

    while (!q.empty())
    {
      int curr = q.front(); // dequeueing and adding into al
      q.pop();
      al.push_back(curr);

      for (int neighbour : adj[curr])
        if (!vis[neighbour])
        {
          vis[neighbour] = true;
          q.push(neighbour);
        }
    }
    return al;
  }
};

int main()
{
  Solution obj;
  int v = 5, e = 5;
  vector<int> adj[v];
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(3);
  adj[3].push_back(4);

  vector<int> ans = obj.bfsOfGraph(5, adj);
  for (auto i : ans)
    cout << i << " ";
  cout << endl;
  return 0;
}