#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int inSequence(int A, int B, int C)
  {
    if (A == B)
    {
      return 1;
    }

    if (C == 0)
    {
      return 0;
    }

    B = B - A;

    if (B % C == 0 && B / C > 0)
    {
      return 1;
    }
    return 0;
  }
};

int main()
{

  int A = 1, B = 3, C = 2;
  Solution ob;
  cout << ob.inSequence(A, B, C) << endl;

  return 0;
}