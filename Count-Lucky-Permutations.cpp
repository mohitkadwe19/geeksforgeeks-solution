#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  bool getBit(int mask, int i)
  {
    return mask & (1 << i);
  }

  vector<vector<ll>> dp;

  ll helper(int prevIdx, int mask, vector<int> &arr, vector<vector<int>> &adj)
  {
    int n = arr.size();

    if (mask == (1 << n) - 1)
      return 1;
    if (dp[prevIdx + 1][mask] != -1)
      return dp[prevIdx + 1][mask];

    int prev = (prevIdx == -1) ? -1 : arr[prevIdx];
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
      if (getBit(mask, i))
        continue;
      int curr = arr[i];

      // pick
      if (prev == -1 || adj[prev][curr])
      {
        ll val = helper(i, mask | (1 << i), arr, adj);
        res += val;
      }
    }

    return dp[prevIdx + 1][mask] = res;
  }

  long long int luckyPermutations(int n, int m, vector<int> arr, vector<vector<int>> graph)
  {

    for (auto &it : arr)
      it--;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (auto it : graph)
    {
      int u = it[0], v = it[1];
      u--, v--;
      adj[u][v] = true;
      adj[v][u] = true;
    }

    dp = vector<vector<ll>>(n + 1, vector<ll>(1 << n, -1));
    int mask = 0;
    return helper(-1, mask, arr, adj);
  }
};

int main()
{
  Solution obj;
  int N = 3, M = 2;
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> graph = {{3, 1}, {1, 2}};
  cout << obj.luckyPermutations(N, M, arr, graph) << endl;
}