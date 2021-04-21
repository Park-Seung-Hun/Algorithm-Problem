/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let left =0 ,right = height.length-1;
    let answer= 0;
    while(left!==right){
        answer = Math.max(answer,(right-left)*Math.min(height[right],height[left]));

        if(height[left]<=height[right]){
            left++;
        }else {
            right--;
        }
    }
    return answer;
};

/*투 포인터*/
