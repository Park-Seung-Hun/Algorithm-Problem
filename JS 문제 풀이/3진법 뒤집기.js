function solution(n) {
    var answer = 0;
    n = n.toString(3);
    n = n.split('').reverse().join('')
    answer = parseInt(n,3);
    return answer;
}

/*
다양한 함수를 다뤄보았다.
1. str.split('') => 문자열을 나눠 배열로 만든다.
2. arr.reverse() => 배열을 뒤집은 배열로 만든다.
3. arr.join('') => 배열을 각 요소마다 합쳐 문자열로 만든다.
4. parseInt(문자열,해당 진법) => 해당 진법으로 표현된 문자열을 10진법으로 만든다.
5. toString(해당 진법)=> 10진법 수를 해당 진법 문자열로 만든다.
*/
