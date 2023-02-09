#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool bpm(vector<vector<int>> &G, int u, vector<bool> &seen, vector<int> &match)
  {
    for (int v = 0; v < G[0].size(); v++)
    {
      if (G[u][v] && !seen[v])
      {
        seen[v] = true;
        if (match[v] < 0 || bpm(G, match[v], seen, match))
        {
          match[v] = u;
          return true;
        }
      }
    }
    return false;
  }
  int maximumMatch(vector<vector<int>> &G)
  {
    int M = G.size(), N = G[0].size();
    vector<int> match(N, -1);
    int count = 0;
    for (int u = 0; u < M; u++)
    {
      vector<bool> seen(N, false);
      if (bpm(G, u, seen, match))
        count++;
    }
    return count;
  }
};

int main()
{
  int M = 3, N = 5;
  vector<vector<int>> G = {{1, 1, 0, 1, 1},
                           {0, 1, 0, 0, 1},
                           {1, 1, 0, 1, 1}};
  Solution ob;
  cout << ob.maximumMatch(G) << endl;
  return 0;
}