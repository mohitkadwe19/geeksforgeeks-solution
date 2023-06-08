#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string kthPermutation(int n, int k)
  {
    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
      fact[i] = i * fact[i - 1];

    vector<int> numbers;
    for (int i = 1; i <= n; i++)
      numbers.push_back(i);

    k--;
    string ans = "";
    for (int i = 1; i <= n; i++)
    {
      int index = k / fact[n - i];
      ans += (numbers[index] + '0');
      numbers.erase(numbers.begin() + index);
      k -= index * fact[n - i];
    }
    return ans;
  }
};

int main()
{
  int N = 4, K = 3;
  Solution ob;
  cout << ob.kthPermutation(N, K) << endl;
  return 0;
}