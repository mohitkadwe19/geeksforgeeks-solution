#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int n, vector<int> p)
  {
    int i, ans = n - 1;
    vector<int> degree(n + 1, 0);
    for (i = 1; i < n; i++)
    {
      degree[p[i]]++;
      degree[i]++;
    }
    for (i = 0; i < n; i++)
      if (degree[i] == 1)
        ans--;

    if (ans < 0)
      return 0;
    return ans;
  }
};

int main()
{
  int N = 5;
  vector<int> p = {4, 3, 1, 2};
  Solution ob;
  cout << ob.solve(N, p) << endl;
  return 0;
}