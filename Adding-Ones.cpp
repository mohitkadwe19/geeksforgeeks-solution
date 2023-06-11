#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void update(int a[], int n, int updates[], int k)
  {
    for (int i = 0; i < k; i++)
    {
      a[updates[i] - 1] += 1;
    }
    for (int i = 1; i < n; i++)
    {
      a[i] = a[i - 1] + a[i];
    }
    return;
  }
};

int main()
{
  int N = 3, K = 4;
  int A[] = {1, 1, 2, 3};
  int updates[] = {0, 1, 1, 2, 1};
  Solution ob;
  ob.update(A, N, updates, K);
  for (int i = 0; i < N; i++)
    cout << A[i] << " ";
  cout << endl;
  return 0;
}