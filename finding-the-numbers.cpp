#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> singleNumber(vector<int> nums)
  {
    sort(nums.begin(), nums.end());
    int i = 0;
    vector<int> ans;
    while (i < nums.size())
    {
      if (nums[i] == nums[i + 1] && i + 1 < nums.size())
      {
        i = i + 2;
      }
      else
      {
        ans.push_back(nums[i]);
        i++;
      }
    }
    return ans;
  }
};

int main()
{
  Solution obj;
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> res = obj.singleNumber(arr);
  for (auto i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}