#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void isprime(vector<int> &v)
  {

    for (int i = 2; i * i < 10000; i++)
    {
      if (v[i] == 1)
      {
        for (int j = i * i; j < 10000; j += i)
        {
          v[j] = 0;
        }
      }
    }
  }
  int shortestPath(int num1, int num2)
  {
    vector<int> v(10000, 1);
    isprime(v);

    queue<pair<int, int>> q;
    unordered_map<int, int> mp;
    q.push({num1, 0});
    mp[num1]++;
    while (!q.empty())
    {

      int n = q.size();
      while (n--)
      {

        auto it = q.front();
        q.pop();
        int l = it.second;
        int num = it.first;
        if (num == num2)
          return l;
        string s = to_string(num);
        for (int i = 0; i < 4; i++)
        {
          string t = s;
          for (int j = 0; j <= 9; j++)
          {
            if (j == 0 && i == 0)
              continue;
            else
            {
              t[i] = (j + '0');

              int x = stoi(t);

              if (mp[x] == 0 && x != num && v[x])
              {
                mp[x]++;
                q.push({x, l + 1});
              }
            }
          }
        }
      }
    }
    return -1;
  }
};

int main()
{
  Solution obj;
  int Num1 = 1033, Num2 = 8179;
  cout << obj.shortestPath(Num1, Num2) << endl;
  return 0;
}