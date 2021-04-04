function solution(n) {
    let answer = 0;
    n=String(n);
    let tmp = n.split('').sort(function(a,b) {return b-a;});
    answer=parseInt(tmp.join(''));
    return answer;
}
