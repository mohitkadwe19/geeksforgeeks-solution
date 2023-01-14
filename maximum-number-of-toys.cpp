#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
  vector<int> maximumToys(int N, vector<int> A, int Q, vector<vector<int>> Queries)
  {
    vector<vector<ll>> temp(N);
    for (ll i = 0; i < N; i++)
    {
      temp[i] = {A[i], i};
    }
    sort(temp.begin(), temp.end());

    vector<ll> sortedA(N), sortedPos(N), prefixSum(N);
    for (ll i = 0; i < N; i++)
    {
      sortedA[i] = temp[i][0];
      sortedPos[temp[i][1]] = i;
      prefixSum[i] = (i ? prefixSum[i - 1] : 0) + sortedA[i];
    }

    vector<int> res;
    for (auto &query : Queries)
    {
      ll cost = query[0];
      ll k = upper_bound(prefixSum.begin(), prefixSum.end(), cost) - prefixSum.begin();
      ll toys = k;

      if (query[1])
      {
        cost -= k ? prefixSum[k - 1] : 0;
        set<ll> s;

        for (ll j = 2; j < query.size(); j++)
        {
          query[j] = sortedPos[query[j] - 1];
          if (query[j] < k)
          {
            cost += sortedA[query[j]];
            toys--;
          }
          else
            s.insert(query[j]);
        }
        while (k < N and cost >= sortedA[k])
        {
          if (s.find(k) == s.end())
          {
            cost -= sortedA[k];
            toys++;
          }
          k++;
        }
      }
      res.push_back(toys);
    }
    return res;
  }
};

int main()
{
  Solution sol;
  int N = 5;
  vector<int> A = {8, 6, 9, 2, 5};
  int Q = 2;
  vector<vector<int>> Query = {{12, 2, 3, 4}, {30, 0}};
  vector<int> ans = sol.maximumToys(N, A, Q, Query);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}