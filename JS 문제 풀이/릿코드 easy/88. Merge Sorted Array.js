/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
  let arr =[];

    let left = 0;
    let right= 0;
    while(true){
        if(nums1[left]>nums2[right]||left===m){
            arr.push(nums2[right++]);
        }
        else if(nums1[left]<=nums2[right]||right===n){
            arr.push(nums1[left++]);
        }

        if(left===m&&right===n) break;
    }
    console.log(arr);

    for(let idx in arr){
        nums1[idx]=arr[idx];
    }
};

/*
투 포인터 알고리즘 사용
*/
