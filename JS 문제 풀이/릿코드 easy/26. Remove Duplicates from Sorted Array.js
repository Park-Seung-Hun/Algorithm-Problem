/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let idx = 0 ;

    if(nums.length===0||nums.length===1) return nums.length;

    while(true){
        if(idx===nums.length-1)break;
        if(nums[idx]===nums[idx+1]){
            nums.splice(idx,1);
        }
        else{
            idx++;
        }

    }
    return nums.length;
};

/*
새로운 배열 없이 기존 입력 배열로만 중복제거 실행.
*/
