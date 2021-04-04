function solution(num) {
    let answer = 0;
    let cnt=0;
    while(true){
         if(num===1||cnt===500)break;
        if(num%2===0) num=parseInt(num/2);
        else num = num*3+1;

        cnt++;

    }
    if(cnt===500) answer=-1;
    else answer=cnt;

    return answer;
}
