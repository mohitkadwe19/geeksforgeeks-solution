#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
  {
    vector<bool> ans;
    int max = *max_element(candies.begin(), candies.end());
    for (int i = 0; i < candies.size(); i++)
    {
      if (candies[i] + extraCandies >= max)
      {
        ans.push_back(true);
      }
      else
      {
        ans.push_back(false);
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> candies = {2, 3, 5, 1, 3};
  int extraCandies = 3;
  vector<bool> ans = s.kidsWithCandies(candies, extraCandies);
  for (auto i : ans)
  {
    cout << i << " ";
  }
  return 0;
}