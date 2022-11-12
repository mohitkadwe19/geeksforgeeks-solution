#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int characterReplacement(string s, int k)
  {

    int n = s.length(), i = 0, j = 0, maxCount = 0, maxLen = 0, freq[26] = {0};

    while (j < n)
    {

      freq[s[j] - 'A']++;

      maxCount = max(maxCount, freq[s[j] - 'A']);

      if (j - i + 1 - maxCount > k)
      {
        freq[s[i] - 'A']--;
        i++;
      }

      maxLen = max(maxLen, j - i + 1);

      j++;
    }

    return maxLen;
  }
};

int main()
{
  Solution sol;
  string s = "ABAB";
  int k = 2;
  cout << sol.characterReplacement(s, k) << endl;
  return 0;
}