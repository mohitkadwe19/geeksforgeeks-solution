#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /* if x is present in arr[] then returns the count
    of occurrences of x, otherwise returns 0. */
  int count(int arr[], int n, int x)
  {
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == x)
        count++;
    }
    return count;
  }
};

int main()
{
  int N = 7, X = 2;
  int arr[] = {1, 1, 2, 2, 2, 2, 3};
  Solution ob;
  cout << ob.count(arr, N, X) << endl;
  return 0;
}