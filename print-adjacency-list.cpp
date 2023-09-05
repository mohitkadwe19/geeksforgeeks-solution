#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to return the adjacency list for each vertex.
  vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
  {
    vector<vector<int>> ans(V);
    for (auto e : edges)
    {
      ans[e.first].push_back(e.second);
      ans[e.second].push_back(e.first);
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  int V = 4;
  vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}};
  vector<vector<int>> ans = sol.printGraph(V, edges);
  for (auto i : ans)
    for (auto j : i)
      cout << j << " ";
  cout << endl;

  return 0;
}