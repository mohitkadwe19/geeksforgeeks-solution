#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int n, int k, vector<int> &stalls)
  {
    int low = 1;
    sort(stalls.begin(), stalls.end());
    int high = stalls.back() - stalls.front();
    int ans = 0;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      int cnt = 1;
      int curr = stalls[0];
      for (int i = 1; i < n && cnt < k; i++)
      {
        if (stalls[i] >= curr + mid)
        {
          cnt++;
          curr = stalls[i];
        }
      }
      if (cnt < k)
      {
        high = mid - 1;
      }
      else
      {
        ans = max(mid, ans);
        low = mid + 1;
      }
    }
    return ans;
  }
};

int main()
{
  int n = 5, k = 3;
  vector<int> stalls = {1, 2, 4, 8, 9};
  Solution s;
  cout << s.solve(n, k, stalls);
  return 0;
}