#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Converts arr[0..n-1] to reduced form.
  void convert(int arr[], int n)
  {
    // Create a copy of arrp[] and sort the copy
    // array. arrp[] is used for keeping the
    // original index of every element.
    int arrp[n];
    for (int i = 0; i < n; i++)
      arrp[i] = arr[i];
    sort(arrp, arrp + n);

    // Traverse all array elements
    for (int i = 0; i < n; i++)
    {
      // Lower bound for current element
      int lb = lower_bound(arrp, arrp + n, arr[i]) - arrp;

      // Assign the lower bound value to current
      // element of original array
      arr[i] = lb;
    }
  }
};

int main()
{
  Solution ob;
  int N = 3, Arr[] = {10, 40, 20};
  ob.convert(Arr, N);
  for (int i = 0; i < N; i++)
    cout << Arr[i] << " ";
  cout << endl;
  return 0;
}