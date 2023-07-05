#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int stockBuyAndSell(int n, vector<int> &prices)
  {
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
      if (prices[i] > prices[i - 1])
        profit += prices[i] - prices[i - 1];
    }
    return profit;
  }
};

int main()
{
  Solution sol;
  int n = 4;
  vector<int> prices = {1, 5, 3, 8};
  cout << sol.stockBuyAndSell(n, prices) << endl;
  return 0;
}