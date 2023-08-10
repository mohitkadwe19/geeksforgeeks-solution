#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find the length of longest common subsequence in two strings.
  int lcs(int n, int m, string s1, string s2)
  {
    int a[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
      {
        if (i == 0 || j == 0)
          a[i][j] = 0;
        else if (s1[i - 1] == s2[j - 1])
          a[i][j] = a[i - 1][j - 1] + 1;
        else
          a[i][j] = max(a[i - 1][j], a[i][j - 1]);
      }
    }
    return a[n][m];
  }
};

int main()
{
  int A = 6, B = 6;
  string str1 = "ABCDGH", str2 = "AEDFHR";
  Solution ob;
  cout << ob.lcs(A, B, str1, str2) << endl;
  return 0;
}