function solution(s){
    var answer = true;
    let p_cnt = 0;
    let y_cnt = 0;
    s = s.toLowerCase();

    for(let char of s){
        if(char === 'p') p_cnt++;
        else if(char === 'y') y_cnt++;
    }

    if(p_cnt===y_cnt) answer=true;
    else answer=false;
    return answer;
}

/*
Tip 문자열도 of 반복문을 사용할 수 있다.
*/
