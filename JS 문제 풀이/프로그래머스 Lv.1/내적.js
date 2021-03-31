function solution(a, b) {
    var answer = 0;
    for(let idx in a){
        answer+= a[idx]*b[idx];
    }
    return answer;
}
