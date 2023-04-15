#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int totalTime(int n, vector<int> &arr, vector<int> &time)
  {
    vector<int> vis(n + 1, 0);
    vis[arr[0]] = 1;
    int c = 0;
    for (int i = 1; i < n; i++)
    {
      if (vis[arr[i]] == 0)
      {
        c++;
        vis[arr[i]]++;
      }
      else
      {
        c += time[arr[i] - 1];
      }
    }
    return c;
  }
};

int main()
{
  int n = 4;
  vector<int> arr = {1, 2, 3, 4};
  vector<int> time = {1, 2, 3, 4};
  Solution ob;
  cout << ob.totalTime(n, arr, time) << endl;
  return 0;
}