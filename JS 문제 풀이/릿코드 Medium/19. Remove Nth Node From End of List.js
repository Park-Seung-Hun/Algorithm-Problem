/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let arr = [];
    let node = new ListNode(0);
    let root = node;
    while(head!==null){
        arr.push(head.val);
        head=head.next;
    }
    arr.splice(arr.length-n,1);

    for(let num of arr){
        node.next = new ListNode(num);
        node = node.next;
    }
    return root.next;
};
