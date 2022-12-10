#include <bits/stdc++.h>
using namespace std;

string buildLowestNumber(string num, int k)
{
  string ans = "";
  for (int i = 0; i < nums.size(); i++)
  {
    if (ans.size() == 0)
    {
      ans.push_back(nums[i]);
    }
    else
    {
      while (k > 0 && ans.size() > 0 && ans.back() > nums[i])
      {
        ans.pop_back();
        k--;
      }
      ans.push_back(nums[i]);
    }
  }
  while (k > 0 && ans.size() > 0)
  {
    ans.pop_back();
  }
  while (ans.size() > 0 && ans.front() == '0')
  {
    ans.erase(ans.begin());
  }
  if (ans.size() == 0)
  {
    ans += "0";
  }
  return ans;
}

int main()
{
  int k = 2;
  string num = "143729";
  cout << buildLowestNumber(num, k) << endl;
}