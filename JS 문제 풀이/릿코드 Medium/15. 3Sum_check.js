/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    const result = [];

    // 1. 숫자 오름차순 정렬
    nums.sort((a,b)=>a-b);

    for(let i=0;i<nums.length-2;i++){
        // 첫 숫자가 0보다 크거나 마지막 숫자가 0보다 작은 경우(절대 세 숫자의 합이 0이 될수 없음)
        if(nums[i]>0||nums[nums.length]<0) break;

        // 이전 숫자와 같은 경우
        if(i>0&&nums[i]===nums[i-1]) continue;

        // 투포인터를 이용한 풀이.
        let left =i+1, right=nums.length-1;

        while(left<right){
            const sum =nums[i]+nums[left]+nums[right];

            if(sum>0) right--;
            else if(sum<0) left++;
            else{
                result.push([nums[i],nums[left],nums[right]]);
                /*중복을 없애기 위한 절차, 동일한 값 요소가 동일한 결과를 생성하기 때문에.*/
                while(left<right&&nums[left]===nums[left+1])left++;
                while(left<right&&nums[right]===nums[right-1])right--;
                left++;
                right--;
            }
        }
    }

    return result;
};
