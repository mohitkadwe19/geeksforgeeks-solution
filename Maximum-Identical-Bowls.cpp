#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getMaximum(int N, vector<int> &arr)
  {
    long long int sum = accumulate(arr.begin(), arr.end(), 0LL);
    for (int i = N; i >= 1; i--)
    {
      if (sum % i == 0)
      {
        return i;
      }
    }
  }
};

int main()
{
  int N = 3;
  vector<int> arr = {1, 2, 3};
  Solution s;
  cout << s.getMaximum(N, arr) << endl;
  return 0;
}