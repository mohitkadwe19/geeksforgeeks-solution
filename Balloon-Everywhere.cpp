#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxInstance(string s)
  {
    int k = s.size();

    int arr[26] = {0};

    for (int i = 0; i < k; i++)
    {
      arr[s[i] - 'a']++;
    }

    int a = arr['b' - 'a'];

    int b = arr['b' - 'a'];

    int l = arr['l' - 'a'] / 2;

    int o = arr['o' - 'a'] / 2;

    int n = arr['n' - 'a'];

    return min(a, min(b, min(l, min(o, n))));
  }
};

int main()
{
  string s = "nlaebolko";
  Solution obj;
  cout << obj.maxInstance(s) << endl;
  return 0;
}