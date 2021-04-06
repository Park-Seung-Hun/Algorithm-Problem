function solution(x, n) {
    let answer = [];
    let ref=x;
    for(let i=0;i<n;i++){

        answer.push(x);
        x=x+ref;
    }
    return answer;
}
