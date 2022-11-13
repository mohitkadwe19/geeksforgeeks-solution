#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int totalWays(int n, vector<int> capacity)
  {
    long long mod = 1e9 + 7;
    sort(capacity.begin(), capacity.end());

    long ways = capacity[0];

    for (int i = 1; i < n; i++)
    {

      ways = (ways * (capacity[i] - i)) % mod;
    }

    return ways;
  }
};

int main()
{
  Solution sol;
  int n = 1;
  vector<int> capacity = {6};
  cout << sol.totalWays(n, capacity) << endl;
  return 0;
}