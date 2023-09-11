#include <bits/stdc++.h>
using namespace std;

bool isLucky(int n)
{
  int count = 2;
  while (true)
  {
    if (n % count == 0)
    {
      return false;
    }
    if (count > n)
    {
      return true;
    }
    n = (n - (n / count));
    count++;
  }
}

int main()
{
  int n = 5;
  cout << isLucky(n);
  return 0;
}