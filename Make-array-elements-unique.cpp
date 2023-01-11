#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int minIncrements(vector<int> arr, int N)
  {
    long long int ans = 0;
    sort(arr.begin(), arr.end());
    for (int i = 1; i < N; i++)
    {
      if (arr[i] <= arr[i - 1])
      {
        ans += arr[i - 1] - arr[i] + 1;
        arr[i] = arr[i - 1] + 1;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int N = 3;
  vector<int> arr = {1, 2, 2};
  cout << s.minIncrements(arr, N) << endl;
  return 0;
}