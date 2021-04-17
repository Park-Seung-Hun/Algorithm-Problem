/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

// 1. O(N) 코드 => 완전 탐색
var searchInsert = function(nums, target) {

    let left = 0;
    let right = nums.length-1;

    while(true){
        if(nums[right]>target){
            right--;
        }
        else if(nums[right]===target){
            return right;
        }
        else return right+1;

    }
};

// 2. O(logN) 코드 => 이분 탐색
var searchInsert = function (nums, target) {
  let left = 0;
  let right = nums.length - 1;
  let middle = Math.floor((left + right) / 2);

  while (nums[middle] !== target && left <= right) {
    if (target < nums[middle]) { // target이 작으면 right를 줄인다.
      right = middle - 1;
    } else { // target이 더크면 left를 늘린다.
      left = middle + 1;
    }
    middle = Math.floor((left + right) / 2);
  }
  // 같아서 while문이 끝난거면 middle, 달라서 마지막에 끝난거면 left의 값을 return한다.
  return nums[middle] === target ? middle : left;
};


/*
여러 탐색 법을 사용하여 확인한다.
*/
