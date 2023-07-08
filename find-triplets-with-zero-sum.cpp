#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find triplets with zero sum.
  bool findTriplets(int arr[], int n)
  {
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
      int l = i + 1, r = n - 1;
      while (l < r)
      {
        int sum = arr[i] + arr[l] + arr[r];
        if (sum == 0)
          return true;
        else if (sum < 0)
          l++;
        else
          r--;
      }
    }
    return false;
  }
};

int main()
{
  int n = 5;
  int arr[n] = {0, -1, 2, -3, 1};
  Solution obj;
  cout << obj.findTriplets(arr, n);
  return 0;
}