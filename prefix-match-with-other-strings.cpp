#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int klengthpref(string arr[], int n, int k, string str)
  {
    int count = 0;
    int len = str.length();
    if (len < k)
      return 0;
    string str2 = str.substr(0, k);
    for (int i = 0; i < n; i++)
    {
      string temp = arr[i].substr(0, k);
      if (temp == str2)
      {
        count++;
      }
    }
    return count;
  }
};

int main()
{
  int n = 6;
  string arr[] = {"abba", "abbb", "abbc", "abbd", "abaa", "abca"};
  string str = "ab";
  int k = 2;
  Solution obj;
  cout << obj.klengthpref(arr, n, k, str) << endl;
  return 0;
}