function solution(n, t, m, p) {
    let answer = '';
    let len=0,cnt=0;
    p-=1;

    for(let i=0;i<=t*m;i++){
        let str = i.toString(n).split('');

        for(let idx =0;idx<str.length;idx++){
            if(p===len%m){
                answer+=str[idx].toUpperCase();
            }
            if(answer.length===t) return answer;
            len++;
        }

    }
    return answer;
}
