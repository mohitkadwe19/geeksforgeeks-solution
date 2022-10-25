let N = 9, K = 3, arr = [1, 2, 3, 1, 4, 5, 2, 3, 6];


class Solution {

  //Function to find maximum of each subarray of size k.
  max_of_subarrays(arr, n, k) {

    let result = [];

    if (k > n || n === 0 || k <= 0 || !!arr === false) {
      return result;
    }

    let max = arr[0];
    let deque = [];

    for (let i = 0; i < n; i++) {

      if (i >= k && deque[0] === arr[i - k]) {
        deque.shift();
      }

      while (deque.length > 0 && deque[deque.length - 1] < arr[i]) {
        console.log('b deque', deque);
        deque.pop();
        console.log('a deque', deque);
      }

      deque.push(arr[i]);

      if (i >= k - 1) {
        result.push(deque[0]);
      }
    }

    return result;

  }
};



let sol = new Solution();
console.log(sol.max_of_subarrays(arr, N, K));