/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let ref =Math.pow(2,31);
    let str = String(x).split('');
    let ans='';

    if(str[0]==='-') ans+=str.shift();
    ans+=str.reverse().join('');
    if(parseInt(ans)>ref-1||parseInt(ans) < -ref) return 0;


    return parseInt(ans);
};

/*
입력값 x를 뒤집어서 출력한다
이때 [-2^31 , 2^31-1]의 범위를 벗어나면 0을 반환
*/
