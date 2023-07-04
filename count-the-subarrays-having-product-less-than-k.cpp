#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
  {
    int count = 0;
    int left = 0;
    int right = 0;
    long long product = 1;
    while (right < n)
    {
      product *= a[right];
      while (left <= right && product >= k)
      {
        product /= a[left];
        left++;
      }
      count += right - left + 1;
      right++;
    }
    return count;
  }
};

int main()
{

  vector<int> a = {1, 2, 3, 4};
  int n = 4;
  long long k = 10;
  Solution sol;
  cout << sol.countSubArrayProductLessThanK(a, n, k) << endl;
  return 0;
}