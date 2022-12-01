//User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} n
 */

class Solution {
  //Function to rearrange  the array elements alternately.
  rearrange(arr, n) {

    // Your code here
    let max = arr[n - 1] + 1;
    let maxIndex = n - 1;
    let minIndex = 0;
    for (let i = 0; i < n; i++) {
      if (i % 2 == 0) {
        arr[i] = arr[i] + (arr[maxIndex] % max) * max;
        maxIndex--;
      } else {
        arr[i] = arr[i] + (arr[minIndex] % max) * max;
        minIndex++;
      }
    }
    for (let i = 0; i < n; i++) {
      arr[i] = Math.floor(arr[i] / max);
    }
    return arr;

  }
}


let n = 6, arr = [1, 2, 3, 4, 5, 6];

let obj = new Solution();
console.log(obj.rearrange(arr, n));