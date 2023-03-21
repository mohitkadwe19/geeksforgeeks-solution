#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumTime(int N, int cur, vector<int> &pos, vector<int> &time)
  {
    int mini = INT_MAX;
    for (int i = 0; i < N; i++)
    {
      mini = min(mini, abs(cur - pos[i]) * time[i]);
    }
    return mini;
  }
};

int main()
{

  int N = 3, cur = 4;
  vector<int> pos = {1, 5, 6}, time = {2, 3, 1};
  Solution ob;
  cout << ob.minimumTime(N, cur, pos, time) << endl;
  return 0;
}