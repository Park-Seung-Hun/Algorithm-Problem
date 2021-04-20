/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node} root
 * @return {number}
 */
var maxDepth = function(root) {
    let answer=0;

    function isEmptyArr(arr)  {
      if(Array.isArray(arr) && arr.length === 0)  {
        return true;
      }
      return false;
    }

    if(root===null) return 0;

    const dfs = function(node,depth){
        if(isEmptyArr(node.children)){
            if(answer<depth) answer=depth;
            return;
        }

        for(let i of node.children){
            dfs(i,depth+1);
        }
    }

    dfs(root,1);
    return answer;
};
