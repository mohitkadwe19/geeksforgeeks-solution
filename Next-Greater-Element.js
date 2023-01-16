/**
 * @param {BigInt[]} arr
 * @param {number} n
 * @returns {BigInt[]}
*/
class Solution {
  nextLargerElement(arr, n) {

    let result = [];
    let stack = [];

    for (let i = n - 1; i >= 0; i--) {
      while (stack.length > 0 && stack[stack.length - 1] <= arr[i]) {
        stack.pop();
      }
      if (stack.length === 0) {
        result[i] = -1;
      } else {
        result[i] = stack[stack.length - 1];
      }
      stack.push(arr[i]);
    }
    return result;

  }
}

let n = 4, arr = [1, 3, 2, 4];
let result = new Solution().nextLargerElement(arr, n);
console.log(result);