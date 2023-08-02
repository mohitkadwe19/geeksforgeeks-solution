#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
  {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
    dist[0][0] = 0;

    while (!q.empty())
    {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++)
      {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] == 1 && dist[nx][ny] > dist[x][y] + 1)
        {
          dist[nx][ny] = dist[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }

    return dist[X][Y] == INT_MAX ? -1 : dist[X][Y];
  }
};

int main()
{
  Solution obj;
  int N = 3, M = 3;
  vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int X = 3, Y = 3;
  cout << obj.shortestDistance(N, M, arr, X, Y) << endl;
  return 0;
}