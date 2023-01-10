#include <bits/stdc++.h>
using namespace std;

void permutation(string S, int l, int r)
{
  if (l == r)
  {
    cout << S << endl;
  }
  else
  {
    for (int i = l; i <= r; i++)
    {
      swap(S[l], S[i]);
      permutation(S, l + 1, r);
      swap(S[l], S[i]);
    }
  }
}

int main()
{
  string S = "AB";
  int N = S.length();
  permutation(S, 0, N - 1);
  return 0;
}