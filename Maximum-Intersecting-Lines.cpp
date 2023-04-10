#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxIntersections(vector<vector<int>> lines, int N)
  {
    map<int, int> mp;
    for (int i = 0; i < lines.size(); i++)
    {
      int a = lines[i][0], b = lines[i][1];
      mp[a]++;
      mp[b + 1]--;
    }
    int ans = INT_MIN, presum = 0;
    for (auto i : mp)
    {
      presum += i.second;
      ans = max(ans, presum);
    }
    return ans;
  }
};

int main()
{
  int N = 4;
  vector<vector<int>> lines = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  Solution ob;
  cout << ob.maxIntersections(lines, N) << endl;
  return 0;
}