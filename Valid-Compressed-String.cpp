#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int checkCompressed(string S, string T)
  {
    int i = 0, j = 0;
    while (i < S.length() && j < T.length())
    {
      if (S[i] == T[j])
      {
        i++;
        j++;
      }
      else if (isdigit(T[j]))
      {
        int num = 0;
        while (j < T.length() && isdigit(T[j]))
        {
          num = num * 10 + (T[j] - '0');
          j++;
        }
        i += num;
      }
      else
      {
        return 0;
      }
    }
    return i == S.length() && j == T.length();
  }
};

int main()
{
  string S = "GEEKSFORGEEKS", T = "G7G3S";
  Solution ob;
  cout << ob.checkCompressed(S, T) << endl;
  return 0;
}