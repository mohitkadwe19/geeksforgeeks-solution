#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestPerfectPiece(int arr[], int N)
  {

    int res = 1, last = 0, max = arr[0], min = arr[0], i = 1, y = 0, mi = 0, si = 0;

    while (i < N)
    {
      if (arr[i] >= max)
      {
        max = arr[i];
        mi = i;
      }
      if (arr[i] <= min)
      {
        min = arr[i];
        si = i;
      }
      if (max - min <= 1)
      {
        y = i - last + 1;
        i++;
        if (y > res)
        {
          res = y;
        }
      }
      else
      {
        if (arr[i] == max)
        {
          si++;
          min = arr[i];
          last = si;
        }
        else
        {
          mi++;
          max = arr[i];
          last = mi;
        }
      }
    }
    return res;
  }
};

int main()
{
  Solution sol;
  int N = 4;
  int arr[] = {8, 8, 8, 8};
  cout << sol.longestPerfectPiece(arr, N) << endl;
  return 0;
}