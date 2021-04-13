function solution(info, query) {
    const answer = [];
    const infoMap = {};

    // 조합 + 이진 탐색

    function combination(array, score, start) {
        const key = array.join("");
        const value = infoMap[key];

        if (value) { // infoMap에 존재 할 경우
            infoMap[key].push(score);
        } else {  // 존재하지 않을 경우
            infoMap[key] = [score];
        }

        for (let i = start; i < array.length; i++) {
            const temp = [...array];
            temp[i] = "-";
            combination(temp, score, i + 1);
        }
    }

    for(const e of info){
        const splited = e.split(" ");
        const score = Number(splited.pop());
        combination(splited,score,0);
    }
    for (const key in infoMap) {
        infoMap[key] = infoMap[key].sort((a, b) => a - b);
    } // '-'를 포함한 모든 경우를 만들어 준다.

    for(const e of query){
        const splited = e.replace(/ and /g, " ").split(" "); // 정규표현식
        const score = Number(splited.pop());
        const key = splited.join("");
        const array = infoMap[key];

        if(array){ // key 값이 존재할 경우 이분 탐색으로 값을 찾는다.
            let start =0;
            let end = array.length;

            while(start<end){
                const mid = Math.floor((start + end) / 2);

                if (array[mid] >= score) {
                    end = mid;
                } else if (array[mid] < score) {
                    start = mid + 1;
                }

            }
            const result = array.length - start
            answer.push(result);

        }else { // 존재하지 않을 경우
            answer.push(0);
        }

    }
    return answer;
}


// 개발언어 항목 / cpp java python
// 지원 직군 항목 / 백엔드 프론트엔드
// 지원 경력 구분 / 주니어 시니어
// 선호하는 소울푸드 / 치킨 피자

// 이런 큰 경우는 이진탐색이나 다른 알고리즘 사용!
