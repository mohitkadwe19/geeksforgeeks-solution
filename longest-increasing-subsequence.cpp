#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find length of longest increasing subsequence.
  int longestSubsequence(int n, int a[])
  {
    vector<int> dp{a[0]};

    for (int i = 0; i < n; i++)
    {
      if (a[i] > dp.back())
        dp.push_back(a[i]);
      else
      {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
      }
    }
    return dp.size();
  }
};

int main()
{
  int N = 16;
  int A[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  Solution ob;
  cout << ob.longestSubsequence(N, A) << endl;
  return 0;
}