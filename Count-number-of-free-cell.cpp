#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<long long int> countZero(int n, int k, vector<vector<int>> &arr)
  {
    vector<long long> res;
    vector<int> rw(n + 1, 0);
    vector<int> col(n + 1, 0);
    int cr = n;
    int cc = n;

    for (auto ele : arr)
    {
      int r = ele[0];
      int c = ele[1];

      if (rw[r] == 0)
      {
        cr--;
      }
      if (col[c] == 0)
      {
        cc--;
      }
      rw[r] = 1;
      col[c] = 1;

      long long c1 = cr, c2 = cc;

      long long z = c1 * n - (n - c2) * (c1);
      res.push_back(z);
    }
    return res;
  }
};

int main()
{
  int n = 3, k = 3;
  vector<vector<int>> arr = {{2, 2},
                             {2, 3},
                             {3, 2}};
  Solution ob;
  vector<long long int> ans = ob.countZero(n, k, arr);
  for (auto i : ans)
    cout << i << " ";
  return 0;
}