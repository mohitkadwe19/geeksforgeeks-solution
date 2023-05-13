#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int bitMagic(int n, vector<int> &arr)
  {

    int l = 0, r = n - 1, ans = 0;
    while (l <= r)
    {
      if (arr[l++] != arr[r--])
      {
        ans++;
      }
    }
    if (ans % 2 == 0)
    {
      return ans / 2;
    }
    return ans / 2 + 1;
  }
};

int main()
{
  int n = 4;
  vector<int> arr = {1, 0, 0, 0};
  Solution ob;
  cout << ob.bitMagic(n, arr) << endl;
  return 0;
}