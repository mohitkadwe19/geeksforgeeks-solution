#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> getDistinctDifference(int N, vector<int> &A)
  {
    vector<int> left(N, 0);
    vector<int> right(N, 0);
    vector<int> res;

    unordered_set<int> s;

    for (int i = 0; i < N; i++)
    {
      left[i] = s.size();
      s.insert(A[i]);
    }
    s.clear();
    for (int i = N - 1; i >= 0; i--)
    {
      right[i] = s.size();
      s.insert(A[i]);
    }

    for (int i = 0; i < N; i++)
    {
      res.push_back(left[i] - right[i]);
    }

    return res;
  }
};

int main()
{
  int N = 3;
  vector<int> A = {4, 3, 3};
  Solution ob;
  vector<int> ans = ob.getDistinctDifference(N, A);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
}