#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int addMinChar(string str)
  {
    int st = 0;

    int end = str.size() - 1;

    int ans = 0;

    while (st <= end)
    {

      // Check the String Index and Ending Index

      if (str[st] == str[end])
      {

        st++;

        end--;
      }
      else
      {

        ans++;

        st = 0;

        end = str.size() - 1 - ans;
      }
    }

    return ans;
    }
};

int main()
{
  string n = "ABCD";
  Solution ob;
  cout << ob.addMinChar(n) << endl;
  return 0;
}