class Solution
{
    //Function to find position of first set bit in the given number.
    public static int getFirstSetBit(int n){
        // code here
        int count = 1;
    while (n > 0 && (n & 1) == 0) {
        n >>= 1;
        count++;
    }
    return n > 0 ? count : 0;   
    }
}