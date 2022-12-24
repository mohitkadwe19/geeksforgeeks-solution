#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int wineSelling(vector<int> &Arr, int N)
  {
    long long ans = 0;

    int neg = 0, pos = 0;

    while (pos < N && neg < N)
    {
      while (Arr[neg] >= 0 && neg < N)
      {
        neg++;
      }
      while (Arr[pos] <= 0 && pos < N)
      {
        pos++;
      }
      if (Arr[pos] > 0 && Arr[neg] < 0)
      {
        if (abs(Arr[neg]) >= Arr[pos])
        {
          int diff = abs(neg - pos);
          ans += (diff * Arr[pos]);
          Arr[neg] += Arr[pos];
          Arr[pos] = 0;
        }
        else
        {
          int diff = abs(neg - pos);
          ans += (diff * abs(Arr[neg]));
          Arr[pos] += Arr[neg];
          Arr[neg] = 0;
        }
      }
      else
      {
        return ans;
      }
    }
    return ans;
  }
};

int main()
{
  Solution ob;
  int N = 5;
  vector<int> Arr = {5, -4, 1, -3, 1};
  cout << ob.wineSelling(Arr, N) << endl;
  return 0;
}