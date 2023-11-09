class Solution {
  int columnWithMaxZeros(int arr[][], int N) {
    // code here
    int max = Integer.MIN_VALUE;
    int count = -1;
    int ans = -1;

    for (int i = 0; i < N; i++) {
      count = 0;

      for (int j = 0; j < N; j++) {
        if (arr[j][i] == 0) {
          count++;
        }
      }
      if (max < count && count != 0) {
        max = count;
        ans = i;
      }
    }
    return ans;
  }
}