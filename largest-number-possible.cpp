#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string findLargest(int N, int S)
  {
    string str = "";
    if (S == 0 && N != 1)
    {
      return "-1";
    }
    else if (S == 0 && N > 1)
    {
      for (int i = 0; i < N; i++)
      {
        str += "0";
      }
      return str;
    }
    if (S > 9 * N)
    {
      return "-1";
    }
    else
    {
      while (N > 0)
      {
        if (S - 9 >= 0)
        {
          S = S - 9;
          str += "9";
        }
        else if (S - 9 < 0)
        {
          str += to_string(S);
          S = 0;
        }
        N--;
      }

      return str;
    }
  }
};

int main()
{
  int N = 2, S = 9;
  Solution obj;
  cout << obj.findLargest(N, S);
  return 0;
}