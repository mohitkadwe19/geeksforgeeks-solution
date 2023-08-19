#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find a continuous sub-array which adds up to a given number.
  vector<int> subarraySum(vector<int> arr, int n, long long s)
  {
    if (s == 0)
    {
      return {-1};
    }
    int i = 0;
    long long sum = 0;
    for (int j = 0; j < n; j++)
    {
      sum += arr[j];
      while (sum > s)
      {
        sum -= arr[i];
        i++;
      }
      if (sum == s)
      {
        return {i + 1, j + 1};
      }
    }
    return {-1};
  }
};

int main()
{
  int N = 5, S = 1;
  vector<int> arr = {1, 4, 20, 3, 10, 5};
  Solution obj;
  vector<int> ans = obj.subarraySum(arr, N, S);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}