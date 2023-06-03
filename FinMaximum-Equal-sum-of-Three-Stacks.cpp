#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2, vector<int> &S3)
  {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < N1; i++)
      sum1 += S1[i];
    for (int i = 0; i < N2; i++)
      sum2 += S2[i];
    for (int i = 0; i < N3; i++)
      sum3 += S3[i];
    int top1 = 0, top2 = 0, top3 = 0;
    while (1)
    {
      if (top1 == N1 || top2 == N2 || top3 == N3)
        return 0;
      if (sum1 == sum2 && sum2 == sum3)
        return sum1;
      if (sum1 >= sum2 && sum1 >= sum3)
        sum1 -= S1[top1++];
      else if (sum2 >= sum1 && sum2 >= sum3)
        sum2 -= S2[top2++];
      else if (sum3 >= sum1 && sum3 >= sum2)
        sum3 -= S3[top3++];
    }
  }
};

int main()
{
  int N1 = 3, N2 = 4, N3 = 2;
  vector<int> S1 = {4, 2, 3};
  vector<int> S2 = {1, 2, 3, 1};
  vector<int> S3 = {3, 2};
  Solution ob;
  cout << ob.maxEqualSum(N1, N2, N3, S1, S2, S3) << endl;
  return 0;
}