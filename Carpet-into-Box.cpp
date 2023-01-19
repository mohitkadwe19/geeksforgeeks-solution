#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int carpetBox(int A, int B, int C, int D)
  {
    int count = 0;
    while (max(A, B) > max(C, D) || min(A, B) > min(C, D))
    {
      if (max(A, B) > max(C, D))
      {
        if (A > B)
        {
          A /= 2;
        }
        else
        {
          B /= 2;
        }
      }
      else
      {
        if (A < B)
        {
          A /= 2;
        }
        else
        {
          B /= 2;
        }
      }
      count++;
    }
    return count;
  }
};

int main()
{
  Solution sol;
  int A = 8, B = 13, C = 6, D = 10;
  cout << sol.carpetBox(A, B, C, D) << endl;
  return 0;
}