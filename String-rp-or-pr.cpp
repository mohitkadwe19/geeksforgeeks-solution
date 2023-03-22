#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long solve(int X, int Y, string s)
  {

    long long ans = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    stack<char> st;
    int n = s.size();

    if (X > Y)
    {
      // pr
      for (int i = 0; i < n; i++)
      {
        if (st.empty())
          st.push(s[i]);

        else if (s[i] == 'r' && st.top() == 'p')
        {
          f1++;
          st.pop();
        }

        else
        {
          st.push(s[i]);
        }
      }

      // rp
      int cnt = 0;
      while (!st.empty())
      {
        if (st.top() == 'p')
        {
          cnt++;
          st.pop();
        }

        else if (st.top() == 'r' && cnt > 0)
        {
          f2++;
          cnt--;
          st.pop();
        }

        else
        {
          st.pop();
          cnt = 0;
        }
      }
    }

    else
    {

      // rp
      for (int i = 0; i < n; i++)
      {
        if (st.empty())
          st.push(s[i]);

        else if (s[i] == 'p' && st.top() == 'r')
        {
          f3++;
          st.pop();
        }

        else
        {
          st.push(s[i]);
        }
      }

      // pr
      int cnt = 0;
      while (!st.empty())
      {
        if (st.top() == 'r')
        {
          cnt++;
          st.pop();
        }

        else if (st.top() == 'p' && cnt > 0)
        {
          f4++;
          cnt--;
          st.pop();
        }

        else
        {
          st.pop();
          cnt = 0;
        }
      }
    }

    ans = (f1 * X) + (f2 * Y) + (f3 * Y) + (f4 * X);
    return ans;
  }
};

int main()
{
  int X = 5, Y = 4;
  cin >> X >> Y;
  string S = "abppprrr";
  Solution ob;
  cout << ob.solve(X, Y, S) << endl;
  return 0;
}