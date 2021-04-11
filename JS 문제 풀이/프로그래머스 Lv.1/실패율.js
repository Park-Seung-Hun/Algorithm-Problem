function solution(N, stages) {
    let answer = [];

    // 클리어 횟수를 나타내는 배열 생성
    let complete = Array.from({length:N+1},()=>0);

    for(let i=0;i<stages.length;i++){
        let stage=stages[i];

        // 클리어한 스테이지 수 체크
        for(let j=1;j<stage;j++){
            complete[j]++;
        }
    }

    let check =[];
    let player=stages.length;
    for(let i=1;i<=N;i++){
        let fail = player-complete[i];
        check.push([fail/player,i]);
        player-=fail;
    }

    check.sort(function (a,b){
        if(a[0]!==b[0]) return b[0]-a[0];
        else{
            return a[1]-b[1];
        }
    })

    for(let arr of check){
        answer.push(arr[1]);
    }

    return answer;
}
