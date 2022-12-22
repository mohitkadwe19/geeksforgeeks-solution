//User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} n
 * @returns {number}
*/
class Solution {
  //Function to count sub arrays with sum equal to 0.
  findSubarray(arr, n) {

    let sum = 0;
    let count = 0;
    let map = new Map();

    for (let i = 0; i < n; i++) {
      sum += arr[i];

      if (sum === 0) {
        count++;
      }

      if (map.has(sum)) {
        count += map.get(sum);
      }

      if (map.has(sum)) {
        map.set(sum, map.get(sum) + 1);
      } else {
        map.set(sum, 1);
      }
    }

    return count;

  }
}

let n = 6, arr = [0, 0, 5, 5, 0, 0];
let obj = new Solution();
console.log(obj.findSubarray(arr, n));
