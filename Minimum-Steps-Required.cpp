#include <bits/stdc++.h>
using namespace std;

int minSteps(string str)
{
  stack<char> s;
  for (int i = 0; i < str.length(); i++)
  {
    if (s.size() == 0)
    {
      s.push(str[i]);
      continue;
    }
    if (s.top() != str[i])
      s.push(str[i]);
  }
  return s.size() / 2 + 1;
}

int main()
{
  string str;
  cin >> str;
  cout << minSteps(str);
}
