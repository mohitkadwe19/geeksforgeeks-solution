#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // arr: input array
  // n: size of array
  // Function to rearrange an array so that arr[i] becomes arr[arr[i]]
  // with O(1) extra space.
  void arrange(long long arr[], int n)
  {
    // Your code here
    for (int i = 0; i < n; i++)
    {
      arr[i] += (arr[arr[i]] % n) * n;
    }
    for (int i = 0; i < n; i++)
    {
      arr[i] /= n;
    }
  }
};

int main()
{
  int N = 2;
  long long A[N] = {1, 0};
  Solution ob;
  ob.arrange(A, N);
  for (int i = 0; i < N; i++)
    cout << A[i] << " ";
  cout << endl;
  return 0;
}