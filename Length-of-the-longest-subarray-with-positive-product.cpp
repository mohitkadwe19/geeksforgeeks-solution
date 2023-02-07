#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to return the length of the
  // longest subarray with ppositive product
  int maxLength(vector<int> &arr, int n)
  {
    int cntl = 0, cntr = 0;   // one from left to right
    int strt = -1, strt2 = n; // another from right to left
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      cntl += arr[i] < 0;
      cntr += arr[n - i - 1] < 0;
      if (arr[i] == 0)
      {
        cntl = 0;
        strt = i;
      }
      if (arr[n - i - 1] == 0)
      {
        cntr = 0;
        strt2 = n - i - 1;
      }

      if (cntl % 2 == 0)
        ans = max(ans, i - strt);
      if (cntr % 2 == 0)
        ans = max(ans, strt2 - n + i + 1);
    }
    return ans;
  }
};

int main()
{
  vector<int> arr = {0, 1, -2, -3, -4};
  int n = arr.size();
  Solution ob;
  cout << ob.maxLength(arr, n) << endl;
  return 0;
}