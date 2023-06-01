#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> topoSort(int V, vector<int> adj[])
  {
    int indegree[V] = {0};
    vector<int> ans;
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
      for (auto x : adj[i])
      {
        indegree[x]++;
      }
    }
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
        ans.push_back(i);
      }
    }

    while (!q.empty())
    {
      int temp = q.front();
      q.pop();
      for (auto i : adj[temp])
      {
        indegree[i]--;
        if (indegree[i] == 0)
        {
          q.push(i);
          ans.push_back(i);
        }
      }
    }
    return ans;
  }
};

int main()
{
  int V = 0;
  vector<int> adj[4];
  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(3);
  Solution obj;
  vector<int> ans = obj.topoSort(V, adj);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}