#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int equalSum(int N, vector<int> &A)
  {
    int sum = 0;
    for (int i = 0; i < N; i++)
      sum += A[i];
    int leftSum = 0;
    for (int i = 0; i < N; i++)
    {
      sum -= A[i];
      if (leftSum == sum)
        return i + 1;
      leftSum += A[i];
    }
    return -1;
  }
};

int main()
{
  int N = 5;
  vector<int> A = {1, 3, 5, 2, 2};
  Solution ob;
  cout << ob.equalSum(N, A) << endl;
  return 0;
}