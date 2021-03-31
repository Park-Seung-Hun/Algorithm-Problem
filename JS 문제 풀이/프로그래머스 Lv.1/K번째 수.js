function compareNum(a,b){
    if(a>b) return 1;
    if(a===b) return 0;
    if(a<b) return -1;
}
function solution(array, commands) {
    let answer = [];

    for(let t=0;t<commands.length;t++){
        const i=commands[t][0];
        const j=commands[t][1];
        const k=commands[t][2];

        let tmp=[];
        for(let r=i-1;r<j;r++){
            tmp.push(array[r]);
        }
        tmp.sort(compareNum);
        answer.push(tmp[k-1]);
    }
    return answer;
}

/*
마찬가지로 조건에 맞는 구현을 하는 문제.

숫자 배열의 정렬
// 오름차순
function compareNum(a,b){
    if(a>b) return 1;
    if(a===b) return 0;
    if(a<b) return -1;
}

// 내림차순
function compareNum(a,b){
    if(a>b) return 1;
    if(a===b) return 0;
    if(a<b) return -1;
}
*/
