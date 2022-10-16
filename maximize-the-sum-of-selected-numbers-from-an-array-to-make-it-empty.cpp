#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximizeSum(int a[], int n)
  {
    unordered_map<int, int> mp;
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
      mp[a[i]]++;
    }
    int ans = 0;
    int i = 0;
    while (i < n)
    {
      if (mp[a[i]] > 0)
      {
        ans = ans + a[i];

        mp[a[i]]--;

        mp[a[i] - 1] > 0;

        mp[a[i] - 1]--;
      }

      i++;
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  int a[] = {1, 2, 3};
  int n = sizeof(a) / sizeof(a[0]);
  cout << sol.maximizeSum(a, n) << endl;
  return 0;
}