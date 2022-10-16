#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
  {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push(source);
    dist[source.first][source.second] = 0;
    visited[source.first][source.second] = true;
    while (!q.empty())
    {
      pair<int, int> curr = q.front();
      q.pop();
      int x = curr.first;
      int y = curr.second;
      if (x == destination.first && y == destination.second)
        return dist[x][y];
      if (x - 1 >= 0 && grid[x - 1][y] == 1 && !visited[x - 1][y])
      {
        q.push({x - 1, y});
        visited[x - 1][y] = true;
        dist[x - 1][y] = dist[x][y] + 1;
      }
      if (x + 1 < n && grid[x + 1][y] == 1 && !visited[x + 1][y])
      {
        q.push({x + 1, y});
        visited[x + 1][y] = true;
        dist[x + 1][y] = dist[x][y] + 1;
      }
      if (y - 1 >= 0 && grid[x][y - 1] == 1 && !visited[x][y - 1])
      {
        q.push({x, y - 1});
        visited[x][y - 1] = true;
        dist[x][y - 1] = dist[x][y] + 1;
      }
      if (y + 1 < m && grid[x][y + 1] == 1 && !visited[x][y + 1])
      {
        q.push({x, y + 1});
        visited[x][y + 1] = true;
        dist[x][y + 1] = dist[x][y] + 1;
      }
    }
    return -1;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{1, 1, 1, 1},
                              {1, 1, 0, 1},
                              {1, 1, 1, 1},
                              {1, 1, 0, 0},
                              {1, 0, 0, 1}};
  pair<int, int> source = {0, 1};
  pair<int, int> destination = {2, 2};
  cout << sol.shortestPath(grid, source, destination) << endl;
  return 0;
}