#include <bits/stdc++.h>
using namespace std;

long long int no_of_subarrays(int n, vector<int> &arr)
{
  long long int count = 0;
  long long int sum = 0;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
    if (sum == 0)
      count++;
    if (mp.find(sum) != mp.end())
      count += mp[sum];
    mp[sum]++;
  }
  return count;
}

int main()
{
  int n = 4;
  vector<int> arr = {0, 0, 1, 0};
  cout << no_of_subarrays(n, arr) << endl;
}