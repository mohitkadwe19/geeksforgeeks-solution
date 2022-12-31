#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minLaptops(int N, int start[], int end[])
  {
    int laptops = 0, maxLaptops = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
      v.push_back({start[i], 1});
      v.push_back({end[i], -1});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
      laptops += v[i].second;
      maxLaptops = max(maxLaptops, laptops);
    }
    return maxLaptops;
  }
};

int main()
{

  Solution sol;
  int N = 3;
  int start[N] = {1, 5, 2}, end[N] = {2, 6, 3};
  cout << sol.minLaptops(N, start, end) << endl;
}