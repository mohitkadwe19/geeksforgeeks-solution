import java.util.*;

class Solution {
  ArrayList<Long> nthRowOfPascalTriangle(int n) {
    ArrayList<Long> arr = new ArrayList<>();
    arr.add((long) 1);

    if (n == 1) {
      return arr;
    }
    arr.add((long) 1);
    if (n == 2) {
      return arr;
    }
    long mod = 1000000007;
    n -= 2;
    while (n != 0) {
      ArrayList<Long> ans = new ArrayList<>();
      long sum = 0;
      ans.add((long) 1);
      for (int i = 0; i < arr.size() - 1; i++) {
        sum = (arr.get(i) + arr.get(i + 1)) % mod;
        ans.add(sum);
      }
      ans.add((long) 1);
      n--;
      arr = ans;
    }

    return arr;

  }
}