function solution(progresses, speeds) {
    let answer = [];
    while(progresses.length !== 0){
        let cnt=0;
        for(let idx in progresses){
            if(progresses[idx]<100) progresses[idx]+=speeds[idx];
        }
        let i=0;
        while(true){
            if(progresses[i]>=100){
                progresses.shift();
                speeds.shift();
                cnt++;
            }
            else break;

            if(progresses.length===0) break;
        }
        if(cnt!==0) answer.push(cnt);
    }
    return answer;
}

// 배포되어야 하는 순서대로 작업의 진도가 적힌 정수배열
// 각 작업의 개발 속도가 적힌 정수 배열 speeds

// 1. 전체 pro에 speeds를 더한다.
// 2. 두번째 확인부터 100이상일시 제거한다. cnt++;
