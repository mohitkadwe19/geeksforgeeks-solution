#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int distributeTicket(int N, int K)
  {
    int x = 1;
    int y = N;
    if (N == K)
      return N;
    while (x < y)
    {
      for (int i = 0; i < K; i++)
      {
        x++;
        if (x >= y)
          return x;
      }
      for (int i = 0; i < K; i++)
      {
        y--;
        if (x >= y)
          return y;
      }
    }
    return 0;
  }
};

int main()
{
  int N = 9, K = 3;
  Solution ob;
  cout << ob.distributeTicket(N, K) << endl;
  return 0;
}