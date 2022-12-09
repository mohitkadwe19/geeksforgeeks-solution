//User function Template for javascript

/**
 * @param {number} n
 * @param {number} m
 * @returns {number}
*/

class Solution {
  //Function to find out the number of ways we can place a black and a 
  //white Knight on this chessboard such that they cannot attack each other.
  numOfWays(n, m) {

    let mod = 1000000007;
    let total = ((n * m) % mod * (n * m - 1) % mod) % mod;

    if (n >= 1 && m >= 2) {
      total -= 4 * (n - 1) * (m - 2);
    }

    if (n >= 2 && m >= 1) {
      total -= 4 * (n - 2) * (m - 1);
    }

    return total;
  }
}

let N = 2, M = 2;
let result = new Solution().numOfWays(N, M);
console.log(result);