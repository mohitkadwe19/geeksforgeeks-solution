#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long dp[100005][2];
  long long f(int i, int p, vector<pair<int, int>> &v)
  {
    if (i == v.size() - 1)
      return 0;
    if (dp[i][p] != -1)
      return dp[i][p];
    long long currp;
    if (p == 0)
      currp = v[i].first;
    else
      currp = v[i].second;
    long long minp = v[i + 1].first;
    long long maxp = v[i + 1].second;
    if (currp >= maxp)
      return dp[i][p] = currp - minp + f(i + 1, 0, v);
    else if (currp <= minp)
      return dp[i][p] = maxp - currp + f(i + 1, 1, v);
    else
    {
      return dp[i][p] = min(currp + maxp - 2 * minp + f(i + 1, 1, v), 2 * maxp - currp - minp + f(i + 1, 0, v));
    }
  }
  long long minTime(int n, vector<int> &loc, vector<int> &type)
  {
    // code here
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
      if (mp.find(type[i]) == mp.end())
        mp[type[i]] = {loc[i], loc[i]};
      else
      {
        mp[type[i]].first = min(mp[type[i]].first, loc[i]);
        mp[type[i]].second = max(mp[type[i]].second, loc[i]);
      }
    }
    vector<pair<int, int>> v;
    v.push_back({0, 0});
    for (auto it : mp)
    {
      v.push_back(it.second);
    }
    memset(dp, -1, sizeof(dp));
    v.push_back({0, 0});
    return f(0, 0, v);
  }
};

int main()
{
  int n = 4;
  vector<int> locations = {1, 3, 5, 7};
  vector<int> types = {1, 1, 2, 2};
  Solution ob;
  cout << ob.minTime(n, locations, types) << endl;
  return 0;
}