#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSubstring(string S)
  {
    int i = 0, count = 0;

    while (i < S.length())
    {
      int j = i + 1;
      int lower = 0;
      int upper = 0;

      if (S[i] >= 'A' && S[i] <= 'Z')
      {
        upper++;
      }
      else
      {
        lower++;
      }

      while (j < S.length())
      {
        if (S[j] >= 'A' && S[j] <= 'Z')
        {
          upper++;
        }
        else
        {
          lower++;
        }

        if (upper == lower)
        {
          count++;
        }
        j++;
      }
      i++;
    }

    return count;
  }
};

int main()
{

  string S = "gEEk";
  Solution ob;
  cout << ob.countSubstring(S) << endl;
  return 0;
}