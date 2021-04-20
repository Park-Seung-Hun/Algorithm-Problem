/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    let answer= [];

    for(let i=0;i<nums.length;i++){
        let ref=0;
        for(let j=i;j>=0;j--){
            ref+=nums[j];
        }
        answer.push(ref);
    }
    return answer;
};
