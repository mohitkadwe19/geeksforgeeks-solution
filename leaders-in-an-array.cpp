#include <bits/stdc++.h>
using namespace std;

class Solution
{
  // Function to find the leaders in the array.
public:
  vector<int> leaders(int a[], int n)
  {
    vector<int> ans;
    int last = a[n - 1];
    ans.push_back(last);
    for (int i = n - 2; i >= 0; i--)
    {
      if (a[i] < last)
      {
        continue;
      }
      else
      {
        last = a[i];
        ans.push_back(last);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution sol;
  int arr[] = {16, 17, 4, 3, 5, 2};
  int n = 6;
  vector<int> ans = sol.leaders(arr, n);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}