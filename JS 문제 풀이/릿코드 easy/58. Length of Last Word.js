/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
   let arr = s.split(' ');
   arr = arr.filter(a => a.length!==0)
    if(arr.length===0) return 0;
    return arr[arr.length-1].length;
};

/*
단순 구현
*/
