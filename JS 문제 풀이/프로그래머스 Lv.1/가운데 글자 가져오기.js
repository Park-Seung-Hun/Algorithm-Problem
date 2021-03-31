function solution(s) {
    var answer = '';
    const size = s.length;
    if(size%2 === 0 ){
        answer = s.slice(size/2-1,size/2+1);
    }else{
        answer = s.slice(size/2,size/2+1);
    }
    return answer;
}

/*
str.substr(시작 지점,길이): 시작 지점에서 길이만큼 반환
str.slice(시작 지점,끝나는 지점): 시작 지점에서 끝나는 지점까지 반환
*/
