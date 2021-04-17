/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let idx = 0 ;

    if(nums.length===0) return nums.length;

    while(true){
        if(idx===nums.length)break;
        if(nums[idx]===val){
            nums.splice(idx,1);
            continue;
        }
        else{
            idx++;
        }
    }
    return nums.length;
};

/*
새로운 배열 없이 기존 입력 배열로만 원소제거 실행.
*/
