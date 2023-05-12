#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int arrayOperations(int n, vector<int> &arr)
  {
    int cnt = 0;
    bool x = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == 0)
      {
        v.push_back(i);
        x = 1;
      }
    }
    for (int i = 1; i < v.size(); i++)
    {
      int diff = v[i] - v[i - 1];
      if (diff > 1)
      {
        cnt++;
      }
    }
    if (arr[0] != 0 and x)
    {
      cnt++;
    }
    if (arr[n - 1] != 0 and x)
    {
      cnt++;
    }
    if (x)
      return cnt;
    return -1;
  }
};

int main()
{
  int n = 4;
  vector<int> arr = {3, 0, 4, 5};
  Solution ob;
  cout << ob.arrayOperations(n, arr) << endl;
  return 0;
}