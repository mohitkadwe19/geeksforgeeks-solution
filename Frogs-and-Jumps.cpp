#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int unvisitedLeaves(int N, int leaves, int frogs[])
  {
    vector<int> leaf(leaves + 1, 1);
    leaf[0] = 0;
    for (int i = 0; i < N; ++i)
    {
      int t = frogs[i];
      if (t == 1)
      {
        return 0;
      }
      if (t <= leaves && leaf[t] != 0)
      {
        for (int j = t; j <= leaves; j += t)
        {
          leaf[j] = 0;
        }
      }
    }
    int c = 0;
    for (int i = 1; i <= leaves; ++i)
    {
      if (leaf[i] == 1)
      {
        ++c;
      }
    }
    return c;
  }
};

int main()
{
  int N = 3, leaves = 4;
  int frogs[N] = {3, 2, 4};
  Solution ob;
  cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
  return 0;
}