#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string removePair(string s)
  {
    stack<char> st;

    for (char x : s)
    {
      if (st.empty() == false && st.top() == x)
      {
        st.pop();
      }
      else
      {
        st.push(x);
      }
    }

    string ans;

    while (st.empty() == false)
    {
      ans.push_back(st.top());
      {
        st.pop();
      }
    };

    reverse(ans.begin(), ans.end());

    if (ans.size() == 0)
    {
      return "-1";
    }
    return ans;
  }
};

int main()
{

  Solution ob;
  string s = "aaabbaaccd";
  cout << ob.removePair(s) << endl;
  return 0;
}