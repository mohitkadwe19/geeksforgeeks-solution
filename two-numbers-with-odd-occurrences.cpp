#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<long long int> twoOddNum(long long int Arr[], long long int N)
  {
    long long int xor1 = 0;
    for (long long int i = 0; i < N; i++)
    {
      xor1 ^= Arr[i];
    }
    long long int set_bit = xor1 & ~(xor1 - 1);
    long long int x = 0, y = 0;
    for (long long int i = 0; i < N; i++)
    {
      if (Arr[i] & set_bit)
        x ^= Arr[i];
      else
        y ^= Arr[i];
    }
    vector<long long int> ans;
    ans.push_back(x);
    ans.push_back(y);
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution sol;
  long long int N = 8;
  long long int Arr[N] = {4, 2, 4, 5, 2, 3, 3, 1};
  vector<long long int> res = sol.twoOddNum(Arr, N);
  for (auto i : res)
    cout << i << " ";
}