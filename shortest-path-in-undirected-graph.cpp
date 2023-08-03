#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
  {
    unordered_map<int, list<pair<int, int>>> adj;

    vector<int> dis(N, 1e9);

    for (auto it : edges)

    {

      adj[it[0]].push_back({it[1], it[2]});
    }

    queue<int> q;

    dis[0] = 0;

    q.push(0);

    while (!q.empty())

    {

      auto it = q.front();

      q.pop();

      for (auto nbr : adj[it])

      {

        if (dis[it] + nbr.second < dis[nbr.first])

        {

          dis[nbr.first] = dis[it] + nbr.second;

          q.push(nbr.first);
        }
      }
    }

    for (int i = 0; i < N; i++)

    {

      if (dis[i] == 1e9)
        dis[i] = -1;
    }

    return dis;
  }
};

int main()
{
  int N = 5, M = 7;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {2, 4}};
  Solution ob;
  ob.shortestPath(N, M, edges);

  return 0;
}