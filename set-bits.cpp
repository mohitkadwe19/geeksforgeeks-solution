#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int setBits(int N)
  {
    int count = 0;
    while (N)
    {
      N = N & (N - 1);
      count++;
    }
    return count;
  }
};

int main()
{
  int N = 6;
  Solution ob;
  cout << ob.setBits(N) << endl;
  return 0;
}