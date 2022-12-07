
// User function Template for javascript

class Node {
  constructor(x) {
    this.data = x;
    this.left = null;
    this.right = null;
  }
}


/**
 * @param {Node} root
 * @param {number} K
 * @return {number}
*/
class Solution {
  KthSmallestElement(root, K) {

    let stack = [], current = root, count = 0;

    while (current || stack.length > 0) {
      while (current) {
        stack.push(current);
        current = current.left;
      }

      current = stack.pop();
      count++;

      if (count === K) {
        return current.data;
      }

      current = current.right;
    }

    return -1;
  }
}

let root = new Node(2);
root.left = new Node(1);
root.right = new Node(3);

console.log(new Solution().KthSmallestElement(root, 3));
