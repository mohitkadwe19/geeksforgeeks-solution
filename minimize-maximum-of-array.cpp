#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSpecialNumbers(int n, vector<int> arr)
  {
    int mx = *max_element(arr.begin(), arr.end());
    vector<int> temp(mx + 1, 0);
    for (int i = 0; i < n; i++)
    {
      if (temp[arr[i]] <= 1)
      {
        for (int j = arr[i]; j <= mx; j += arr[i])
        {
          temp[j]++;
        }
      }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      if (temp[arr[i]] > 1)
        count++;
    }
    return count;
  }
};

int main()
{
  int N = 3;
  vector<int> arr = {2, 3, 6};
  Solution ob;
  cout << ob.countSpecialNumbers(N, arr) << endl;
  return 0;
}