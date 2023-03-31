#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> lexicographicallyLargest(vector<int> &a, int n)
  {
    int count = 0;
    int c = 2;
    for (int i = 0; i < n - 1;)
    {
      if ((a[i] + a[i + 1]) % 2 == 0)
      {
        if (a[i] < a[i + 1])
        {
          swap(a[i], a[i + 1]);
          if (i != 0)
          {
            i--;
          }
        }
        else
        {
          i++;
        }
      }
      else
        i++;
    }
    return a;
  }
};

int main()
{

  int n = 3;
  vector<int> a = {1, 3, 5};
  Solution ob;
  vector<int> ans = ob.lexicographicallyLargest(a, n);
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}