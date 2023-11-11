import java.util.*;

class Solution {
  // Function to check if two strings are isomorphic.
  public static boolean areIsomorphic(String str1, String str2) {
    if (str1.length() != str2.length()) {
      return false;
    }
    HashMap<Character, Character> map = new HashMap<>();
    for (int i = 0; i < str1.length(); i++) {
      char c1 = str1.charAt(i);
      char c2 = str2.charAt(i);
      if (map.containsKey(c1)) {
        if (map.get(c1) != c2) {
          return false;
        }
      } else {
        if (map.containsValue(c2)) {
          return false;
        }
        map.put(c1, c2);
      }
    }
    return true;
  }
}