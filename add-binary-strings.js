/**
 * @param {string} A
 * @param {string} B
 * @returns {string}
 */

class Solution {
  addBinary(A, B) {

    let result = '';
    let carry = 0;
    let i = A.length - 1;
    let j = B.length - 1;
    while (i >= 0 || j >= 0) {
      let a = i >= 0 ? A[i] : 0;
      let b = j >= 0 ? B[j] : 0;
      let sum = parseInt(a) + parseInt(b) + carry;
      result = (sum % 2) + result;
      carry = Math.floor(sum / 2);
      i--;
      j--;
    }
    if (carry > 0) {
      result = carry + result;
    }

    // remove leading zeros
    while (result[0] === '0') {
      result = result.slice(1);
    }

    return result;

  }
}

let A = "1101", B = "111";
let obj = new Solution();
console.log(obj.addBinary(A, B));
