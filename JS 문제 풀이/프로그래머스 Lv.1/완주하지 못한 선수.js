function solution(participant, completion) {
    participant.sort();
    completion.sort();

    for(let i=0;i<participant.length;i++){
        if(participant[i] != completion[i]) return participant[i];
    }
}

// 1명의 선수를 제외하곤 모두 완주
// 완주한 선수들의 이름이 담긴 배열 completion
// 완주하지 못한 선수의 이름 반환
/*
sol. 각 배열을 정렬한 후 참가자 배열의 길이 만큼 진행.
1. 다른 참가자의 이름이 나오면 return
2. 도착한 모든 사람을 확인하면 남은 참가자 1명이 return
*/
console.log(solution(	["leo", "kiki", "eden"], ["eden", "kiki"])) //leo
console.log(solution(	["marina", "josipa", "nikola", "vinko", "filipa"], ["josipa", "filipa", "marina", "nikola"])) //vinko
console.log(solution(		["mislav", "stanko", "mislav", "ana"], ["stanko", "ana", "mislav"])) //mislav
