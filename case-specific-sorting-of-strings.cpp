#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to perform case-specific sorting of strings.
  string caseSort(string str, int n)
  {
    // code here
    vector<char> lower, upper;
    for (int i = 0; i < n; i++)
    {
      if (str[i] >= 'a' && str[i] <= 'z')
      {
        lower.push_back(str[i]);
      }
      else
      {
        upper.push_back(str[i]);
      }
    }
    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());
    int i = 0, j = 0, k = 0;
    while (i < n)
    {
      if (str[i] >= 'a' && str[i] <= 'z')
      {
        str[i] = lower[j++];
      }
      else
      {
        str[i] = upper[k++];
      }
      i++;
    }
    return str;
  }
};

int main()
{
  string str = "defRTSersUXI";
  Solution ob;
  cout << ob.caseSort(str, str.length()) << endl;
  return 0;
}