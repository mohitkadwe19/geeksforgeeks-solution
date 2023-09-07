#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  const int MAXN = 1e5 + 5;
  const int MOD = 100000;
  int minimumMultiplications(vector<int> &arr, int start, int end)
  {
    int n = arr.size();

    vector<bool> visited(MAXN, false);
    visited[start] = true;

    queue<int> q;
    q.push(start);

    int steps = 0;
    while (!q.empty())
    {
      int qsize = q.size();

      for (int i = 0; i < qsize; i++)
      {
        int x = q.front();
        q.pop();

        if (x == end)
        {
          return steps;
        }

        for (int num : arr)
        {
          int newX = (x * 1LL * num) % MOD;

          if (!visited[newX])
          {
            q.push(newX);
            visited[newX] = true;
          }
        }
      }
      steps++;
    }
    return -1;
  }
};

int main()
{
  vector<int> arr = {2, 5, 7};
  int start = 3, end = 30;
  Solution ob;
  cout << ob.minimumMultiplications(arr, start, end) << endl;
  return 0;
}