#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool is_possible_to_get_seats(int n, int m, vector<int> &seats)
  {
    int count = 0;
    for (int i = 0; i < m; i++)
    {
      if (!seats[i])
        if ((i - 1 < 0 || seats[i - 1] == 0) && (i + 1 >= m || seats[i + 1] == 0))
        {
          count++;
          seats[i] = 1;
        }
    }
    return count >= n;
  }
};

int main()
{
  int n = 2, m = 7;
  vector<int> seats = {0, 0, 1, 0, 0, 0, 1};
  Solution s;
  cout << s.is_possible_to_get_seats(n, m, seats) << endl;
  return 0;
}