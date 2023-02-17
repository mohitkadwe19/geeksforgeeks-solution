#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long solve(int N, int K, vector<long long> GeekNum)
  {
    long long sum = 0;
    for (int i = 0; i < K; i++)
    {
      sum += GeekNum[i];
    }
    int left = 0;
    for (int right = K; right < N; right++)
    {
      long long newElement = sum;
      GeekNum.push_back(newElement);
      sum += newElement;
      sum -= GeekNum[left];
      left++;
    }
    return GeekNum[N - 1];
  }
};

int main()
{

  int N = 6, K = 1;
  vector<long long> GeekNum = {4};
  Solution ob;
  cout << ob.solve(N, K, GeekNum) << endl;

  return 0;
}