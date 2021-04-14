/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let ref = String(x).split('').reverse().join('');
    if(ref===String(x)) return true;
    else return false;
};

/*
입력받은 숫자 x를 뒤집은 문자열과 x가 같을때 true 아니면 false.
*/
