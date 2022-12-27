/**
 * @param {number[]} arr
 * @param {number} n
 * @returns {number} 
 */

class Solution {
  maxArea(arr, n) {

    let maxArea = 0;
    let left = 0, right = n - 1;

    while (left < right) {
      maxArea = Math.max(maxArea, Math.min(arr[left], arr[right]) * (right - left));

      if (arr[left] < arr[right]) {
        left++;
      } else {
        right--;
      }
    }

    return maxArea;

  }
}

let N = 4, a = [1, 5, 4, 3];
let obj = new Solution();
console.log(obj.maxArea(a, N));
