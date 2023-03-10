#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxTripletProduct(long long arr[], int n)
  {
    sort(arr, arr + n);

    return max(arr[n - 1] * arr[n - 2] * arr[n - 3], arr[n - 1] * arr[0] * arr[1]);
  }
};

int main()
{
  int n = 4;
  long long arr[n] = {1, 2, 3, 5};
  Solution ob;
  cout << ob.maxTripletProduct(arr, n) << endl;
  return 0;
}