function solution(n) {
    var answer = [];
    n=String(n);
    answer = n.split('').map(Number);
    answer.reverse();
    return answer;
}
