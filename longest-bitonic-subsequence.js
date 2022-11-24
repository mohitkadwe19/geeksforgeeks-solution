/**
 * @param {number[]} nums
 * @return {number}
 */

class Solution {
  LongestBitonicSequence(nums) {

    let n = nums.length;
    let lis = new Array(n).fill(1);
    let lds = new Array(n).fill(1);

    for (let i = 1; i < n; i++) {
      for (let j = 0; j < i; j++) {
        if (nums[i] > nums[j] && lis[i] < lis[j] + 1) {
          lis[i] = lis[j] + 1;
        }
      }
    }

    for (let i = n - 2; i >= 0; i--) {
      for (let j = n - 1; j > i; j--) {
        if (nums[i] > nums[j] && lds[i] < lds[j] + 1) {
          lds[i] = lds[j] + 1;
        }
      }
    }

    let max = lis[0] + lds[0] - 1;
    for (let i = 1; i < n; i++) {
      if (lis[i] + lds[i] - 1 > max) {
        max = lis[i] + lds[i] - 1;
      }
    }

    return max;

  }
}

let nums = [1, 2, 5, 3, 2];
let solution = new Solution();
let result = solution.LongestBitonicSequence(nums);
console.log(result);