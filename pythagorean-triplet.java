class Solution {
  boolean checkTriplet(int[] arr, int n) {
    HashSet<Integer> set = new HashSet<>();
    for (int i = 0; i < n; i++) {
      arr[i] = arr[i] * arr[i];
      set.add(arr[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (set.contains((arr[i] + arr[j])))
          return true;
      }
    }
    return false;
  }
}