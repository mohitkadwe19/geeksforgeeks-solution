#include <bits/stdc++.h>
using namespace std;

struct alphanumeric
{
  string name;
  int count;
};
class Solution
{
public:
  vector<alphanumeric> sortedStrings(int N, vector<string> A)
  {
    vector<alphanumeric> ans;
    map<string, int> m;
    for (int i = 0; i < N; i++)
    {
      m[A[i]]++;
    }
    for (auto i : m)
    {
      alphanumeric temp;
      temp.name = i.first;
      temp.count = i.second;
      ans.push_back(temp);
    }
    sort(ans.begin(), ans.end(), [](alphanumeric a, alphanumeric b)
         {
      if (a.name.length() == b.name.length())
      {
        return a.name < b.name;
      }
      return a.name.length() < b.name.length(); });

    return ans;
  }
};

int main()
{
  Solution s;
  int n = 3;
  vector<string> v = {"2234597891 zmxvvxbcij 8800654113 jihgfedcba",
                      "1234567891 abcdefghij 9876543219 jihgfedcba",
                      "2234597891 zmxvvxbcij 8800654113 jihgfedcba"};
  vector<alphanumeric> ans = s.sortedStrings(n, v);
  for (auto i : ans)
  {
    cout << i.name << " " << i.count << endl;
  }
  return 0;
}