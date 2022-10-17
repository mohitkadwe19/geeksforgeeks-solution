#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findLeastGreater(vector<int> &arr, int n)
  {
    vector<int> result(n);

    set<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
      s.insert(arr[i]);

      auto it = s.find(arr[i]);

      it++;

      if (it == s.end())
      {

        result[i] = -1;
      }
      else
      {
        result[i] = *it;
      }
    }
    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
  int n = arr.size();
  vector<int> ans = sol.findLeastGreater(arr, n);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
