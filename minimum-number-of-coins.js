/**
 * @param {number} N
 * @return {number[]}
 */

class Solution {

  minPartition(N) {

    const coins = [1, 2, 5, 10, 20, 50, 100, 200, 500, 2000];
    const result = [];
    let i = coins.length - 1;
    while (N > 0) {
      if (coins[i] <= N) {
        N -= coins[i];
        result.push(coins[i]);
      } else {
        i--;
      }
    }
    return result;

  }
}

let N = 43;
let obj = new Solution();
console.log(obj.minPartition(N));
