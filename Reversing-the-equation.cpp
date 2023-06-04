#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reverseEqn(string s)
  {
    stack<string> st;
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] >= '0' && s[i] <= '9')
      {
        temp += s[i];
      }
      else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
      {
        st.push(temp);
        temp = "";
        st.push(string(1, s[i]));
      }
    }
    st.push(temp);
    string ans = "";
    while (!st.empty())
    {
      ans += st.top();
      st.pop();
    }
    return ans;
  }
};

int main()
{
  string str = "20-3+5*2";
  Solution ob;
  cout << ob.reverseEqn(str) << endl;
  return 0;
}