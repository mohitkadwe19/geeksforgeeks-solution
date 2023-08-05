#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long findMinDiff(vector<long long> a, long long n, long long m)
  {
    sort(a.begin(), a.end());
    long long ans = INT_MAX;
    int i = 0, j = m - 1;
    for (int i = 0; j < n; i++, j++)
    {
      ans = min(ans, a[j] - a[i]);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<long long> a = {3, 4, 1, 9, 56, 7, 9, 12};
  cout << s.findMinDiff(a, 8, 4);
  return 0;
}