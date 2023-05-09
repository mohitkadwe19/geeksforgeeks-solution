#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  const int mod = 1e9 + 7;

  vector<vector<long long int>> multiply(vector<vector<long long int>> &a, vector<vector<long long int>> &b)
  {
    vector<vector<long long int>> ans(2, vector<long long int>(2, 0));
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        for (int k = 0; k < 2; k++)
          ans[i][j] += (a[i][k] * b[k][j]) % mod;
      }
    }
    return ans;
  }

  vector<vector<long long int>> matrix(vector<vector<long long int>> &v, long long int n)
  {
    if (n == 0)
      return {{1, 0}, {0, 1}};
    if (n == 1)
      return v;
    vector<vector<long long int>> temp = matrix(v, n / 2);
    vector<vector<long long int>> ans = multiply(temp, temp);
    if (n % 2)
      ans = multiply(v, ans);
    return ans;
  }

  int countStrings(long long int N)
  {
    vector<vector<long long int>> v = {{1, 1}, {1, 0}};
    vector<vector<long long int>> ans = matrix(v, N);
    return (ans[0][1] + ans[0][0]) % mod;
  }
};

int main()
{
  long long int n = 3;
  Solution ob;
  cout << ob.countStrings(n) << endl;
  return 0;
}