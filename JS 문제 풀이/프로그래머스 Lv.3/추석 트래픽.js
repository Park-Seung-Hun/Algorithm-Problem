function solution(lines) {
    let answer = 0;
    let Res = [];

    for(let i=0;i<lines.length;i++){
        let arr = lines[i].split(' ');
        arr.shift();

        /*
            시간을 구분
            이때 시간을 모두 msec초로 변환한다.
            끝나는 시간(1) => 시간S를 msec로 변환한 시간
            시작 시간(0) => 끝나는 시간에 1msec을 더하고 시간 T만큼 빼준다 (시작및 완료 시간을 포함하기 때문에.)
            두 시간을 각각 flag와 함께 Res에 넣는다.
        */
        let S_arr = arr[0].split(':');
        let sec = S_arr.pop().split('.');
        S_arr.push(sec[0],sec[1]);

        let T_arr = arr[1].split('');
        T_arr.pop();
        T_arr=Number(T_arr.join(''));

        let end = (parseInt(S_arr[0])*3600+parseInt(S_arr[1])*60+parseInt(S_arr[2]))*1000+parseInt(S_arr[3]);
        let start = end +1 - T_arr*1000;

        /*
            종료시간에 999msec를 더해준 이유는 종료 지점과 다른 시작 지점이 1초이내에 있는 것을 고려.
        */
        Res.push([end+999,1]);
        Res.push([start,0]);
    }

    /*
        Res에 입력된 시작시간과 종료시간을 정렬한다. 이때
        1. 시간의 오름차순
        2. 시간이 같으면 시작시간 - 종료시간 순으로 정렬한다.
    */
    Res.sort(function(a,b){
        if(a[0]!==b[0]) return a[0]-b[0];
        return a[1]-b[1];
    })

    /*
        시작 시간일 경우 cnt+1
        종료 시간일 경우 cnt-1
    */
    let cnt=0;
    for(let tmp of Res){

        if(tmp[1]===0)cnt++;
        else cnt--;

        answer = Math.max(answer,cnt);
    }
    return answer;
}

/*
9월 15일 로그 데이터를 분석한 후 초당 최대 처리량을 계산.
초당 최대 처리량? => 요청의 응답 완료 여부에 관계없이 임의 시간부터 1초간 처리하는 요청의 최대 개수
[S,T] S 응답완료 시간, T 처리 시간 (시작시간과 끝시간을 포함한 시간) => T는 3초이하 0.001초 이상이다.

*/
