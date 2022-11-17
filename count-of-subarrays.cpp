#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  ll countSubarray(int arr[], int n, int k)
  {
    ll p = -1;
    ll count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      if (arr[i] > k)
      {
        count += n - i;
        p = i;
      }
      else if (p != -1)
      {
        count += n - p;
      }
    }
    return count;
  }
};

int main()
{
  Solution sol;
  int N = 3, K = 2, Arr[] = {3, 2, 1};
  cout << sol.countSubarray(Arr, N, K) << endl;
  return 0;
}