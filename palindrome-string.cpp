#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int isPalindrome(string S)
  {
    int result = 1;
    string chars = S;
    for (int i = 0; i < chars.length(); i++)
    {
      if (chars[i] != chars[chars.length() - 1 - i])
      {
        result = 0;
        break;
      }
    }
    return result;
  }
};

int main()
{
  string S = "abba";
  Solution obj;
  cout << obj.isPalindrome(S);
  return 0;
}