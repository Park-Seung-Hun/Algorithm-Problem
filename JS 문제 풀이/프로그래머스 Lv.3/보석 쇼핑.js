function solution(gems) {
    let answer = [0, 100001];

    let gemLen = new Set(gems).size;
    let gemMap = new Map();

    console.log(gemLen,gemMap)

    for(let i=0;i<gems.length;i++){
        gemMap.delete(gems[i]); // Map에 보석이 존재하면 삭제.
        gemMap.set(gems[i],i+1); // Map에 보석 담기

        if(gemMap.size === gemLen){ // Map에 담긴 보석이 전체 보석인 경우
            /*
                가장 중요한 포인트.
                gemMap.values().next().value => gemMap의 가장 처음 들어온 value
                gemMap.keys().next().value => gemMap의 가장 처음 들어온 key
            */
            const tmpIdx = [gemMap.values().next().value, i + 1];
            const answerLen = answer[1] - answer[0];
            const mapLen = tmpIdx[1] - tmpIdx[0];

            if (answerLen > mapLen) {
                answer = tmpIdx;
            }
        }
    }
    return answer;
}
/*
    Tip 1. Map, Set 객체를 잘 사용하자
    Map안에 들어간 요소 확인하는 방법

    for(let arr of Map.entries()){
        console.log(arr); // [key,value]
    }
*/
