class Solution {
    // Function to check if Kth bit is set or not.
    checkKthBit(n, k) {
        return n & (1 << k);
    }
}