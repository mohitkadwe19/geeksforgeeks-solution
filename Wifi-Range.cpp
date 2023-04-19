#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool wifiRange(int N, string S, int X)
  {
    int sum = 0;

    // loop through all rooms
    for (int i = 0; i < N; i++)
    {
      // if there is no wifi in current room, decrease sum by 1
      if (S[i] == '0')
      {
        sum--;
      }
      // if there is wifi in current room and no wifi in any of the
      // previous rooms
      // check if the range of the wifi covers all previous rooms
      else if (S[i] == '1' && sum < 0)
      {
        if (X + sum < 0)
        {
          // if the range of the wifi does not cover all previous
          // rooms, return false
          return false;
        }
        else
        {
          // if the range of the wifi covers all previous rooms,
          // update sum to X
          sum = X;
        }
      }
      // if there is wifi in current room and wifi in some of the
      // previous rooms
      else if (sum >= 0)
      {
        // update sum to X
        sum = X;
      }
    }

    // if the sum is negative at the end, it means some rooms at the
    // end were not covered by any wifi, return false
    if (sum < 0)
    {
      return false;
    }

    // if all rooms are covered by wifi, return true
    return true;
  }
};

int main()
{
  int N = 3, X = 0;
  string S = "1 2 3";
  Solution ob;
  cout << ob.wifiRange(N, S, X) << endl;
  return 0;
}