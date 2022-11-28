#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findSubarray(int a[], int n)
  {
    vector<int> ans, tans;

    ans.push_back(-1);

    int sum = 0, tmp = 0;

    for (int i = 0; i < n; i++)
    {
      if (a[i] < 0)
      {
        if (sum < tmp)
        {
          ans.resize(0);
          for (auto x : tans)
          {
            ans.push_back(x);
          }
          tans.resize(0);
        }

        sum = max(tmp, sum);

        tmp = 0;

        tans.resize(0);
      }

      else
      {
        tans.push_back(a[i]);
        tmp += a[i];
      }
    }

    if (sum < tmp)
    {
      ans.resize(0);
      for (auto x : tans)
      {
        ans.push_back(x);
      }
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  int n = 3;
  int a[n] = {1, 2, 3};
  vector<int> ans = sol.findSubarray(a, n);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}