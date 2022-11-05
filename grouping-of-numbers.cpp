#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxGroupSize(int arr[], int N, int K)
  {
    // Your code goes here
    map<int, int> ma;

    for (int i = 0; i < N; i++)
    {
      ma[arr[i] % K]++;
    }

    int low = 1;

    int high = K - 1;

    int ans = 0;

    while (low <= high)
    {

      if (low == high and ma[low] > 0)
      {

        ans++;

        break;
      }

      ans += max(ma[low], ma[high]);

      low++;

      high--;
    }

    if (ma[0] > 0)
    {

      ans++;
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  int N = 4, K = 8, arr[] = {1, 7, 2, 6};
  cout << sol.maxGroupSize(arr, N, K) << endl;
  return 0;
}