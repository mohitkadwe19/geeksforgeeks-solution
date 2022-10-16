#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findSum(int A[], int N)
  {
    // code here.
    int maxNum = INT_MIN;
    int minNum = INT_MAX;
    for (int i = 0; i < N; i++)
    {
      maxNum = max(maxNum, A[i]);
      minNum = min(minNum, A[i]);
    }
    return maxNum + minNum;
  }
};

int main()
{
  Solution sol;
  int A[] = {-2, 1, -4, 5, 3};
  int N = sizeof(A) / sizeof(A[0]);
  cout << sol.findSum(A, N) << endl;
  return 0;
}