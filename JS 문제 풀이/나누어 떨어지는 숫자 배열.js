function compareNum(a,b){
    if(a>b) return 1;
    if(a===b)return 0;
    if(a<b)return -1;
}
function solution(arr, divisor) {
    var answer = [];
    for(let num of arr) {
        if(num%divisor === 0) answer.push(num);
    }
    if(answer.length === 0 )answer.push(-1);
    answer.sort(compareNum);
    return answer;
}

// 오름차순 내림차순 순서 잘 정하기
