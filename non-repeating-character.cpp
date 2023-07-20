#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find the first non-repeating character in a string.
  char nonrepeatingCharacter(string S)
  {
    map<char, int> ma;
    for (auto &i : S)
      ma[i]++;
    for (auto &i : S)
    {
      if (ma[i] == 1)
        return i;
    }
    return '$';
  }
};

int main()
{
  Solution obj;
  string S = "abcabcbb";
  cout << obj.nonrepeatingCharacter(S) << endl;
  return 0;
}