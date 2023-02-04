#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // calculate the maximum sum with out adjacent
  int findMaxSum(int *arr, int n)
  {
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for (i = 1; i < n; i++)
    {
      /* current max excluding i */
      excl_new = (incl > excl) ? incl : excl;

      /* current max including i */
      incl = excl + arr[i];
      excl = excl_new;
    }

    /* return max of incl and excl */
    return ((incl > excl) ? incl : excl);
  }
};

int main()
{

  int n = 6;
  int a[n] = {5, 5, 10, 100, 10, 5};
  Solution ob;
  cout << ob.findMaxSum(a, n) << endl;
  return 0;
}