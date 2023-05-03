#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxSweetness(vector<int> &a, int n, int k)
  {

    int l = 1;
    int h = 0;

    for (int i = 0; i < n; i++)
    {
      h += a[i];
    }

    // int ans;
    while (l <= h)
    {
      int mid = l + (h - l) / 2;

      int piece = 0;
      int sweet = 0;
      for (int i = 0; i < n; i++)
      {
        sweet += a[i];

        if (sweet >= mid)
        {
          piece++;
          sweet = 0;
        }
      }

      if (piece < k + 1)
      {
        h = mid - 1;
      }
      else
      {
        // ans = mid;
        l = mid + 1;
      }
    }

    return h;
  }
};

int main()
{
  int N = 6, K = 2;
  vector<int> sweetness = {6, 3, 2, 8, 7, 5};
  Solution obj;
  cout << obj.maxSweetness(sweetness, N, K) << endl;
  return 0;
}