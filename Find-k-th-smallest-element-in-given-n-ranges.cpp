#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> kthSmallestNum(int n, vector<vector<int>> &range, int q, vector<int> queries)
  {
    sort(range.begin(), range.end());
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
      int query = queries[i];
      int temp = 0;
      bool flag = false;
      for (int j = 0; j < range.size(); j++)
      {
        if (j == 0)
        {
          temp += range[j][0] - 0 - 1;
        }
        if (j > 0)
        {
          if (range[j][0] > range[j - 1][1])
            temp += range[j][0] - range[j - 1][1] - 1;
        }

        if (query + temp >= range[j][0] and query + temp <= range[j][1])
        {
          // cout << query+temp << " ";
          ans.push_back(query + temp);
          flag = true;
          break;
        }
      }
      if (!flag)
      {
        ans.push_back(-1);
      }
    }
    return ans;
  }
};

int main()
{
  int n = 2, q = 3;
  vector<vector<int>> range = {{1, 5}, {10, 15}};
  vector<int> queries = {1, 12, 15};
  Solution ob;
  vector<int> ans = ob.kthSmallestNum(n, range, q, queries);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}