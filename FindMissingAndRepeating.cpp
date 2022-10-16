#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int *findTwoElement(int *arr, int n)
  {
    // code here
    int *ans = new int[n];
    int i = 0;
    while (i < n)
    {
      if (arr[i] != arr[arr[i] - 1])
      {
        swap(arr[i], arr[arr[i] - 1]);
      }
      else
      {
        i++;
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (arr[i] != i + 1)
      {
        ans[0] = arr[i];
        ans[1] = i + 1;
      }
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  int n = 2;
  int arr[n] = {2, 2};
  int *ans = sol.findTwoElement(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
}