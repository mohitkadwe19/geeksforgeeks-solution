#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isStraightHand(int N, int groupSize, vector<int> &hand)
  {
    if (N % groupSize != 0)
      return false;
    map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
      mp[hand[i]]++;
    }
    for (auto it : mp)
    {
      if (it.second > 0)
      {
        for (int i = 1; i < groupSize; i++)
        {
          if (mp[it.first + i] < it.second)
            return false;
          mp[it.first + i] -= it.second;
        }
      }
    }
    return true;
  }
};

int main()
{
  int N, groupSize;
  cin >> N >> groupSize;
  vector<int> hand(N);
  for (int i = 0; i < N; i++)
  {
    cin >> hand[i];
  }
  Solution obj;
  cout << obj.isStraightHand(N, groupSize, hand) << endl;
  return 0;
}