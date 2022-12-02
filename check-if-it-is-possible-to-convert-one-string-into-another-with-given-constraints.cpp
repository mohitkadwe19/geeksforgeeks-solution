#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int isItPossible(string S, string T, int M, int N)
  {
    if (M != N)
    {
      return 0;
    }
    for (int i = 0; i < N; i++)
    {
      if (T[i] == 'A')
      {
        int j = i;
        while (j < N)
        {
          if (T[i] == S[j])
          {
            swap(S[i], S[j]);
            S[i] = 'y';
            T[i] = 'y';
            break;
          }
          if (S[j] == 'B' || S[j] == 'x')
          {
            break;
          }
          j++;
        }
      }
      if (T[i] == 'B')
      {
        int j = i;
        while (j >= 0)
        {
          if (T[i] == S[j])
          {
            swap(S[i], S[j]);
            S[i] = 'x';
            T[i] = 'x';
            break;
          }
          if (S[j] == 'A' || S[j] == 'y')
          {
            break;
          }
          j--;
        }
      }
    }

    if (S == T)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
};

int main()
{
  Solution sol;
  string S = "#A#B#B#", T = "A###B#B";
  int M = S.length(), N = T.length();
  cout << sol.isItPossible(S, T, M, N) << endl;
  return 0;
}