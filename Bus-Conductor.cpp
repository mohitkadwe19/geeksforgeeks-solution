#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMoves(int n, vector<int> chairs, vector<int> passengers)
  {
    sort(chairs.begin(), chairs.end());
    sort(passengers.begin(), passengers.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += abs(chairs[i] - passengers[i]);
    }
    return ans;
  }
};

int main()
{
  vector<int> chairs = {3, 1, 5};
  vector<int> passengers = {2, 7, 4};
  int n = 5;
  Solution obj;
  cout << obj.findMoves(n, chairs, passengers) << endl;
  return 0;
}