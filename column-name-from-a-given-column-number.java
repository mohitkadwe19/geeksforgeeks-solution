class Solution
{
    String colName (long n)
    {
        StringBuilder ans = new StringBuilder();

        while (n > 0) {
            n--;
            ans.append((char) ('A' + n % 26));

            n = n / 26;
        }
      return ans.reverse().toString();
    }
    public static void main (String[] args){
        long n = 28;
        System.out.println(colName(n));
    }
}