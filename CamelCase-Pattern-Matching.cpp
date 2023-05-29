#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern)
  {
    vector<string> v;

    for (int i = 0; i < N; i++)
    {
      string s = Dictionary[i];
      int k = 0;

      for (int j = 0; j < s.length(); j++)
      {
        if (isupper(s[j]))
        {
          if (s[j] != Pattern[k++])
          {
            break;
          }
        }

        if (k == Pattern.length())
        {
          v.push_back(Dictionary[i]);
          break;
        }
      }
    }

    if (v.empty())
    {
      return {"-1"};
    }

    return v;
  }
};

int main()
{
  int N = 5;
  vector<string> Dictionary = {"Hi", "Hello", "HelloWorld", "HiTech", "HiGeek"};
  string Pattern = "HA";
  Solution obj;
  vector<string> ans = obj.CamelCase(N, Dictionary, Pattern);
  for (auto i : ans)
    cout << i << " ";
  cout << endl;
  return 0;
}