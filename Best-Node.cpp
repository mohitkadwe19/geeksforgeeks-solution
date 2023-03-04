#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  void dfs(int u, vector<int> g[], vector<int> &a, vector<ll> &neg, vector<ll> &pos, ll &ans)
  {

    pos[u] = a[u - 1];
    neg[u] = -a[u - 1];

    ll bestpos = -1e18, bestneg = -1e18;

    for (auto &v : g[u])
    {
      dfs(v, g, a, neg, pos, ans);
      bestpos = max(bestpos, pos[v]);
      bestneg = max(bestneg, neg[v]);
    }

    if (bestpos != -1e18)
    {
      neg[u] += bestpos;
      pos[u] += bestneg;
    }

    ans = max(ans, pos[u]);
  }

  long long bestNode(int n, vector<int> &a, vector<int> &p)
  {
    vector<int> g[n + 1];
    for (int i = 1; i < n; i++)
    {
      g[p[i]].push_back(i + 1);
    }

    ll ans = -1e18;
    vector<ll> neg(n + 1), pos(n + 1);
    dfs(1, g, a, neg, pos, ans);
    return ans;
  }
};

int main()
{

  return 0;
}