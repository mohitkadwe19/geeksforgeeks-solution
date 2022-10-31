#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> satisfyEqn(int A[], int N)
  {
    vector<int> ans;
    // equation A + B = C + D
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        for (int k = 0; k < N; k++)
        {
          for (int l = 0; l < N; l++)
          {
            if (A[i] + A[j] == A[k] + A[l] and i != j and k != l and j != k and i != k and j != l and i != l)
            {
              ans.push_back(i);
              ans.push_back(j);
              ans.push_back(k);
              ans.push_back(l);
              return ans;
            }
          }
        }
      }
    }
    ans = {-1, -1, -1, -1};
    return ans;
  }
};

int main()
{
  Solution sol;
  int N = 4;
  int A[] = {1, 2, 3, 4};
  vector<int> ans = sol.satisfyEqn(A, N);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
}