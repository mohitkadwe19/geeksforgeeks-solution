#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int appleSequences(int n, int m, string arr)
  {
    int i = 0;
    int ans = 0;
    int j = 0;
    int k = 0;
    while (i < n)
    {
      if (arr[i] == 'A')
      {

        ans = max(i - k + 1, ans);
      }
      else if (arr[i] == 'O' && j < m)
      {

        ans = max(ans, i - k + 1);
        j++;
      }
      else
      {
        while (arr[k] == 'A')
        {
          k++;
        }
        k++;
      }
      i++;
    }
    return ans;
  }
};

int main()
{

  int n = 5, m = 1;
  string arr = "AAOAO";
  Solution ob;
  cout << ob.appleSequences(n, m, arr) << endl;

  return 0;
}