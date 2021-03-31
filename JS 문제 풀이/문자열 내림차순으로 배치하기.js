function solution(s) {
    var answer = '';
    let array = s.split('');

    array.sort(function(a,b){
        if(a<b)return 1;
        if(a===b) return 0;
        if(a>b) return -1;
    })
    // 내림차순

    answer = array.join('');
    return answer;
}

/*
정렬 함수 Tip.
이 함수가 a, b 두개의 element를 파라미터로 입력받을 경우,
이 함수가 리턴하는 값이 0보다 작을 경우,  a가 b보다 앞에 오도록 정렬하고,
이 함수가 리턴하는 값이 0보다 클 경우, b가 a보다 앞에 오도록 정렬합니다.
만약 0을 리턴하면, a와 b의 순서를 변경하지 않습니다.

*/
