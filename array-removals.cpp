#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int removals(vector<int> &arr, int k)
  {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int start = 0;

    int end = 0;

    int maxSize = INT_MIN;

    while (end < n)
    {

      int diff = arr[end] - arr[start];

      if (diff > k)
      {

        start++;
      }
      else
      {

        maxSize = max(maxSize, end - start);

        end++;
      }
    }

    return n - (maxSize + 1);
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {1, 3, 4, 9, 10, 11, 12, 17, 20};
  int k = 4;
  cout << sol.removals(arr, k) << endl;
  return 0;
}