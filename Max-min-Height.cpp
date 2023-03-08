#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  long long int maximizeMinHeight(int n, int k, int w, vector<int> &a)
  {
    ll l = *min_element(a.begin(), a.end()) + 1, r = l + k, ans = l - 1;
    auto works = [&](ll mnheight)
    {
      ll days = 0, prefsum = 0;
      vector<ll> dp(n + 1);
      for (int i = 0; i < n; i++)
      {
        prefsum += dp[i];
        int height = a[i] + prefsum;
        if (height < mnheight)
        {
          int add = mnheight - height;
          days += add;
          prefsum += add;
          dp[i] += add;
          dp[min(n, i + w)] -= add;
        }
      }
      return days <= k;
    };

    while (l <= r)
    {
      int guessheight = (l + r) / 2;
      if (works(guessheight))
      {
        ans = guessheight;
        l = guessheight + 1;
      }
      else
        r = guessheight - 1;
    }
    return ans;
  }
};

int main()
{

  int n = 6, k = 2, w = 3;
  vector<int> a = {2, 2, 2, 2, 1, 1};
  Solution ob;
  cout << ob.maximizeMinHeight(n, k, w, a) << endl;
  return 0;
}