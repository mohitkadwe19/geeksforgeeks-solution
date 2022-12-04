#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string rearrange(string S, int N)
  {
    map<char, int> mp1;
    map<char, int> mp2;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < N; i++)
    {
      if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u')
      {
        mp1[S[i]]++;
        count1++;
      }
      else
      {
        mp2[S[i]]++;
        count2++;
      }
    }
    if (count1 == count2)
    {
      string ans1 = "";
      string ans2 = "";
      for (auto it : mp1)
      {
        for (int i = 0; i < it.second; i++)
          ans1 += it.first;
      }
      for (auto it : mp2)
      {
        for (int i = 0; i < it.second; i++)
          ans2 += it.first;
      }
      int x = ans1.size() - 1;
      int y = ans2.size() - 1;
      int a = 0, b = 0;
      string ans = "";
      while (a <= x || b <= y)
      {
        int p = ans1[0] - 'a';
        int q = ans2[0] - 'a';
        if (p < q)
        {
          ans += ans1[a];
          ans += ans2[b];
        }
        else
        {
          ans += ans2[a];
          ans += ans1[b];
        }
        a++;
        b++;
      }
      return ans;
    }
    else if (count1 == count2 + 1)
    {
      string ans1 = "";
      string ans2 = "";
      for (auto it : mp1)
      {
        for (int i = 0; i < it.second; i++)
          ans1 += it.first;
      }
      for (auto it : mp2)
      {
        for (int i = 0; i < it.second; i++)
          ans2 += it.first;
      }
      int x = ans1.size() - 1;
      int y = ans2.size() - 1;
      int a = 0, b = 0;
      string ans = "";
      while (a <= x || b <= y)
      {

        ans += ans1[a];
        ans += ans2[b];
        a++;
        b++;
      }
      return ans;
    }
    else if (count1 + 1 == count2)
    {
      string ans1 = "";
      string ans2 = "";
      for (auto it : mp1)
      {
        for (int i = 0; i < it.second; i++)
          ans1 += it.first;
      }
      for (auto it : mp2)
      {
        for (int i = 0; i < it.second; i++)
          ans2 += it.first;
      }
      int x = ans1.size() - 1;
      int y = ans2.size() - 1;
      int a = 0, b = 0;
      string ans = "";
      while (a <= x || b <= y)
      {

        ans += ans2[a];
        ans += ans1[b];
        a++;
        b++;
      }
      return ans;
    }
    else
    {
      return "-1";
    }
  }
};

int main()
{
  Solution sol;
  string S = "aeroplane";
  int N = 7;
  cout << sol.rearrange(S, N) << endl;
}