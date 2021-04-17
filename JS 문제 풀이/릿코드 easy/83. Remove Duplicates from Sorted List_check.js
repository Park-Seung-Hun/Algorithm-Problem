/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    let arr = [-101];
    let node = new ListNode(-101);
    let root = node;

    while(head!=null){
        if(head!=null){
            if(arr[arr.length-1]!==head.val) arr.push(head.val);
            head=head.next;
        }
    }

    arr.shift();
    for(let num of arr){
        node.next = new ListNode(num);
        node = node.next;
    }
    return root.next;
};
