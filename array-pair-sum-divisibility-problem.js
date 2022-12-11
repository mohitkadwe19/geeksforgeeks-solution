// User function Template for javascript

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */

class Solution {
  canPair(nums, k) {

    if (nums == null) {
      return false;
    }
    let n = nums.length;
    if (n < 2 || (n & 1) != 0) {
      return false;
    }
    let mem = new Array(k);

    for (let i = 0; i < n; i++) {
      let rem = nums[i] % k;
      if (rem < 0) {
        rem += k;
      }
      if (mem[rem] == null) {
        mem[rem] = 0;
      }
      mem[rem]++;
    }

    if ((mem[0] & 1) != 0) {
      return false;
    }
    for (let i = 1; i <= k / 2; i++)
      if (mem[i] != mem[k - i]) {
        return false;
      }

    return true;

  }
}

let arr = [9, 5, 7, 3], k = 6;
let ans = new Solution().canPair(arr, k);
console.log(ans);