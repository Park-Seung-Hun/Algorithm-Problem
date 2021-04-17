/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let a1=0;
    let a2=nums[0];

    for(let idx=0;idx<nums.length;idx++){
        a1 = Math.max(nums[idx], a1+nums[idx]);
        a2=Math.max(a2,a1);
    }
    return a2;
};

/*
카데인 알고리즘 : 배열의 최대 부분 합을 O(n)의 시간 복잡도로 구하는 알고리즘.
*/
