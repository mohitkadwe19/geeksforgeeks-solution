#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool lemonadeChange(int N, vector<int> &bills)
  {
    int five = 0, ten = 0;
    for (int i = 0; i < N; i++)
    {
      if (bills[i] == 5)
        five++;
      else if (bills[i] == 10)
      {
        if (five == 0)
          return false;
        five--;
        ten++;
      }
      else
      {
        if (five > 0 && ten > 0)
        {
          five--;
          ten--;
        }
        else if (five >= 3)
          five -= 3;
        else
          return false;
      }
    }
    return true;
  }
};

int main()
{
  vector<int> bills = {5, 5, 5, 10, 20};
  int N = 5;
  Solution obj;
  cout << obj.lemonadeChange(N, bills) << endl;
  return 0;
}