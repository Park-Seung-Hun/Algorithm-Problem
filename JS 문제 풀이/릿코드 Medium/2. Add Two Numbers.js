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
var addTwoNumbers = function(l1, l2) {

    let tmp=0,L1=0,L2=0;

    let List = new ListNode(0);
    let root=List;


    while(l1 !==null || l2!==null){

        if(l1!=null) {
            L1=l1.val;
            l1=l1.next;
        }

        if(l2!=null) {
            L2=l2.val;
            l2=l2.next;
        }


        let l = L1+L2+tmp;
        L1=0; L2=0;

        if(l>=10) {
            l-=10;
            tmp=1;
        }else tmp=0;

        List.next = new ListNode(l);
        List=List.next;
    }
    if(tmp===1) {
         List.next = new ListNode(tmp);
        List=List.next;
    }
    return root.next;
};

/*
2개의 비어있지 않은 링크드 리스트가 주어질때.(양의 정수)
*/
