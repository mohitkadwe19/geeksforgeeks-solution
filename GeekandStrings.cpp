#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
  vector<int> prefixCount(int N, int Q, string li[], string query[])
  {
    vector<int> ans;
    unordered_map<string, int> map;
    for (int i = 0; i < N; i++)
    {
      string str = li[i];
      string s = "";
      for (int j = 0; j < str.length(); j++)
      {
        s += str.substr(j, 1);
        map[s]++;
      }
    }
    for (int i = 0; i < Q; i++)
    {
      string str = query[i];
      ans.push_back(map[str]);
    }
    return ans;
  }
};

int main()
{
  Solution sol;
  int N = 5, Q = 5;
  string li[] = {"abracadabra", "geeksforgeeks", "abracadabra", "geeks", "geeksthrill"};
  string query[] = {"abr", "geeks", "geeksforgeeks", "ge", "gar"};
  vector<int> ans = sol.prefixCount(N, Q, li, query);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}