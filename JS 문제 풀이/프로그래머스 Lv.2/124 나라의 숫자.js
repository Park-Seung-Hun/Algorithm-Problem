function solution(n) {
    let answer = '';
    while(n!==0){
         if(n%3===0) {
            answer+='4';
            n=Math.floor(n/3);
            n--;
        }
        else if(n%3===1) {
            answer+='1';
            n=Math.floor(n/3);
        }
        else if(n%3===2) {
            answer+='2';
            n=Math.floor(n/3);
        }

    }
    answer = answer.split('').reverse().join('');
    return answer;
}

/*
규칙을 잘 찾아야한다
*/
