#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<long long> smallerSum(int n, vector<int> &arr)
  {
    vector<int> A = arr;
    vector<long long> prefixSum{0}, ans;

    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++)
      prefixSum.push_back(prefixSum[i] + A[i]);

    for (int i = 0; i < n; i++)
    {
      int p = lower_bound(A.begin(), A.end(), arr[i]) - A.begin();
      ans.push_back(prefixSum[p]);
    }

    return ans;
  }
};

int main()
{
  int n = 5;
  vector<int> arr = {1, 2, 3, 4, 5};
  Solution ob;
  vector<long long> ans = ob.smallerSum(n, arr);
  for (auto i : ans)
    cout << i << " ";
  return 0;
}