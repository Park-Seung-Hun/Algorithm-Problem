function solution(d, budget) {
    let answer = 0;
    let len=d.length;

    d.sort(function (a,b) {return a-b;})

    for(let i=0;i<len;i++){
        if(budget - d[i]<0)break;
        answer++;
        budget-=d[i];
    }
    return answer;
}
