#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findRange(string str, int n)
  {
    vector<int> v;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
      if (str[i] - '0' == 1)
      {
        count++;
      }
    }

    if (count == n)
    {
      return {-1};
    }

    int max = 0, sum = 0, p = 0, left = 0, right = 0, s;

    for (int i = 0; i < n; i++)
    {

      if (str[i] - '0' == 0)
      {
        s = 1;
      }
      else
      {
        s = -1;
      }

      sum = sum + s;

      if (sum > max)
      {
        max = sum;
        left = p, right = i;
      }
      else if (sum < 0)
      {
        p = i + 1;
        sum = 0;
      }
    }

    v.push_back(left + 1);

    v.push_back(right + 1);

    return v;
  }
};

int main()
{
  int N = 3;
  string str = "111";
  Solution sol;
  vector<int> v = sol.findRange(str, N);
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  return 0;
}