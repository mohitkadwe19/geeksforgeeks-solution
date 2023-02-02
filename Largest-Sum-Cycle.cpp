#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  long long ans = -1;
  void dfs(int node, long long sum, vector<int> &adj, vector<int> &pref, vector<int> &vis)
  {
    if (node == -1 or (vis[node] and pref[node] == -1))
      return;
    if (vis[node] and pref[node] != -1)
    {
      ans = max(ans, sum - pref[node]);
      return;
    }
    vis[node] = true;
    pref[node] = sum;
    dfs(adj[node], sum + node, adj, pref, vis);
    pref[node] = -1;
  }

public:
  long long largestSumCycle(int N, vector<int> edge)
  {
    vector<int> pref(N, -1), vis(N);
    for (int node = 0; node < N; node++)
    {
      dfs(node, 0, edge, pref, vis);
    }
    return ans;
  }
};

int main()
{

  int N = 4;
  vector<int> Edge = {1, 2, 0, -1};
  Solution ob;
  cout << ob.largestSumCycle(N, Edge) << endl;
  return 0;
}