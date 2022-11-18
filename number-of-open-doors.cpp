#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int noOfOpenDoors(long long N)
  {
    return sqrt(N);
  }
};

int main()
{
  Solution sol;
  int N = 2;
  cout << sol.noOfOpenDoors(N) << endl;
  return 0;
}