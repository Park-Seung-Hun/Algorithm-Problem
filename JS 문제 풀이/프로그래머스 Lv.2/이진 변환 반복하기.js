function solution(s) {
    let answer = [];
    let cnt =0;
    let bicnt=0;
    while(s!=='1'){
        let len=s.split('').filter(char => char!=='0').length;
        bicnt+=(s.split('').length-len);

        let binary = len.toString(2);
        s=binary;
        cnt++;
    }

    answer.push(cnt,bicnt);
    return answer;
}
