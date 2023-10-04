class Solution {
    // Finds decimal value of a given roman numeral
    public int romanToDecimal(String str) {
        HashMap<Character, Integer> map = new HashMap<>();

        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);

        int sum = 0;
        int i = 0;
        for (; i < str.length() - 1; i++) {
            if (map.get(str.charAt(i)) >= map.get(str.charAt(i + 1))) {
                sum += map.get(str.charAt(i));
            } else {
                sum += -map.get(str.charAt(i));
            }
        }

        sum += map.get(str.charAt(i));
        return sum;
    
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.romanToDecimal("MCMXCIV"));
    }
}