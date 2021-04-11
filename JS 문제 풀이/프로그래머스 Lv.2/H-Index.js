function solution(citations) {
    let answer = 0;

    citations.sort(function (a,b){
        return b-a;
    });

    for(let idx=0;idx<citations.length;idx++){
        if(citations[idx]<=answer) break;
        answer++;
    }
    return answer;
}
