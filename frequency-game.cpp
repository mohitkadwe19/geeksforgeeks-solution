#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int LargButMinFreq(int arr[], int n)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      m[arr[i]]++;
    }

    int mini = INT_MAX;
    int ans = -1;
    for (auto k : m)
    {
      if (k.second < mini)
      {
        ans = k.first;
        mini = k.second;
      }
      else if (k.second == mini && k.first > ans)
      {
        ans = k.first;
      }
    }

    return ans;
  }
};

int main()
{
  int arr[] = {2, 2, 5, 50, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  Solution obj;
  cout << obj.LargButMinFreq(arr, n) << endl;
  return 0;
}