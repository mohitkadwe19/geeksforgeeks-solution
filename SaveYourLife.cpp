#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string maxSum(string w, char x[], int b[], int n)
  {
    if (w.size() == 1)
    {
      return w;
    }

    unordered_map<char, int> mpp;

    for (int i = 0; i < n; i++)

      mpp[x[i]] = b[i];

    int ans = 0;

    string res;

    string subs;

    int sub = 0;

    for (char ch : w)

    {

      subs += ch;

      if (mpp.count(ch) > 0)

        sub += mpp[ch];

      else

        sub += int(ch);

      if (sub > ans)

      {

        res = subs;

        ans = sub;
      }

      if (sub < 0)
      {
        sub = 0;
        subs = "";
      }
    }
    return res;
  }
};

int main()
{
  Solution ob;
  string W = "abcde";
  int N = 1, B[] = {-1000};
  char X[] = {'c'};
  cout << ob.maxSum(W, X, B, N);
  return 0;
}