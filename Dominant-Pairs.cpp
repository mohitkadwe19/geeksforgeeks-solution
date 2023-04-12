#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dominantPairs(int n, vector<int> &arr)
  {
    int mid = n / 2;
    sort(arr.begin(), arr.begin() + n / 2);
    sort(arr.begin() + n / 2, arr.end());
    int i = (n / 2) - 1;
    int j = n - 1;
    int count = 0;
    while (j >= (n / 2) && i >= 0)
    {
      if (arr[i] >= 5 * arr[j])
      {
        count = count + (j - ((n / 2) - 1));
        i--;
      }
      else
      {
        j--;
      }
    }
    return count;
  }
};

int main()
{
  int n = 4;
  vector<int> arr = {10, 2, 2, 1};
  Solution ob;
  cout << ob.dominantPairs(n, arr) << endl;
  return 0;
}