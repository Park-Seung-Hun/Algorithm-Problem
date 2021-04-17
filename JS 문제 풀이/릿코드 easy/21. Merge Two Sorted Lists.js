/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    let arr = [];
    let node = new ListNode(0); // 현재 node가 0인 Linked list 생성
    let root = node; // root = 0

    while(l1 !==null || l2!==null){
        if(l1!=null) {
            arr.push(l1.val);
            l1=l1.next;
        }

        if(l2!=null) {
            arr.push(l2.val);
            l2=l2.next;
        }
    } // l1, l2가 null이 될때까지 이동

    arr.sort((a,b)=>a-b);

    for(let num of arr){
        node.next = new ListNode(num);
        node = node.next;
    }

    return root.next;
};

/*
Linked List 실제 동작

*/
