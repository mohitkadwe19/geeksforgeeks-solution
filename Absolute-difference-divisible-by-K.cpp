#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long countPairs(int n, int arr[], int k)
  {
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
      mp[arr[i] % k]++;
    }
    long long res = 0;
    for (auto x : mp)
    {
      res = res + (x.second * (x.second - 1)) / 2;
    }
    return res;
  }
};

int main()
{
  int n = 3, arr[] = {3, 7, 11}, k = 4;
  Solution ob;
  cout << ob.countPairs(n, arr, k) << endl;
  return 0;
}