#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxOnes(int a[], int n)
  {
    int maxi = 0, initial = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (a[i] == 1)
        initial++;
    }
    for (int i = 0; i < n; i++)
    {
      if (a[i] == 1)
      {
        if (cnt > 0)
        {
          cnt--;
        }
        else
        {
          cnt = 0;
        }
      }
      else
      {
        cnt++;
      }
      maxi = max(maxi, cnt);
    }
    return initial + maxi;
  }
};

int main()
{
  Solution obj;
  int n = 3;
  int arr[] = {1, 0, 1};
  cout << obj.maxOnes(arr, n);
  return 0;
}