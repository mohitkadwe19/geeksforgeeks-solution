#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> optimalArray(int n, vector<int> &a)
  {
    vector<int> ans;
    vector<int> dp;
    dp.push_back(a[0]);
    for (int i = 1; i < n; ++i)
    {
      dp.push_back(dp.back() + a[i]);
    }
    for (int i = 0; i < n; ++i)
    {
      if (i == 0)
      {
        ans.push_back(0);
        continue;
      }
      int start = 0;
      int end = i;
      int len = end - start + 1;
      if (len % 2 == 0)
      {
        int mid = (end + start) / 2;
        int l = a[mid];
        int r = a[mid + 1];
        int ele = (l + r) / 2;
        int l_sum = dp[mid];
        int r_sum = dp[i] - dp[mid];
        int ab = (ele * (len / 2) - l_sum) + (r_sum - ele * (len / 2));
        ans.push_back(ab);
      }
      else
      {
        int mid = (end + start) / 2;
        int ele = a[mid];
        int l_sum = dp[mid - 1];
        int r_sum = dp[i] - dp[mid];
        int ab = (ele * (len / 2) - l_sum) + (r_sum - ele * (len / 2));
        ans.push_back(ab);
      }
    }
    return ans;
  }
};

int main()
{

  int n = 4;
  vector<int> a = {1, 6, 9, 12};
  Solution ob;
  vector<int> ans = ob.optimalArray(n, a);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}