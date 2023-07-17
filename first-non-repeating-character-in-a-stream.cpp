#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string FirstNonRepeating(string A)
  {
    unordered_map<char, int> mp;
    string ans = "";
    queue<char> q;

    ans += A[0];
    mp[A[0]]++;
    q.push(A[0]);
    for (int i = 1; i < A.length(); i++)
    {
      mp[A[i]]++;
      while (mp[q.front()] > 1 && !q.empty())
      {
        q.pop();
      }
      if (mp[A[i]] == 1)
      {
        q.push(A[i]);
      }
      if (q.empty())
      {
        ans += '#';
      }
      else
      {
        ans = ans + q.front();
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string A = "aabc";
  cout << s.FirstNonRepeating(A);
  return 0;
}