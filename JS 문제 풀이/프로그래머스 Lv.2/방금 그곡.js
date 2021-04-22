function solution(m, musicinfos) {
    let answer = [];
    let checkTime=0;
    /* 음악 제목, 재생이 시직되고 끝난 시각, 악보 */
    /* C, C#, D, D#, E, F, F#, G, G#, A, A#, B */
    /* 각 음은 1분에 1개 음악길이 > 재생시간 : 처음부터 반복해서 재생 , 음악길이 < 재생시간 : 처음부터 재생시간 만큼 재생*/
    const changeMusic = function(str){
        let stack = [];
        let arr = str.split('');

        for(let i=0;i<arr.length;i++){
            if(arr[i]==='#'){
                stack.push(stack.pop().toLowerCase());
            }
            else stack.push(arr[i]);
        }
        return stack.join('');
    }

    m=changeMusic(m);
    let arr = [] ;
    let tmp = [] ;
    for(let i=0;i<musicinfos.length;i++){
        // 시작 , 종료 , 제목 , 악보 순으로 나누기
        arr.push(musicinfos[i].split(','));

        // 종료 - 시작 후 분으로 만들기
        let startT = arr[i][0].split(':');
        let start = parseInt(startT[0])*60+parseInt(startT[1]);

        let endT = arr[i][1].split(':');
        let end = parseInt(endT[0])*60+parseInt(endT[1]);
        let Time = end-start;

        arr[i][3]=changeMusic(arr[i][3]);
        let music='';
        // 음악 길이 >= 재생시간
        if(arr[i][3].length>=Time){
            music=arr[i][3].substr(0,Time);
        }
        // 음악 길이 < 재생시간
        else{
            let repeat = parseInt(Time/arr[i][3].length);
            let module = parseInt(Time%arr[i][3].length);
            for(let r=0;r<repeat;r++) music+=arr[i][3];
            music+=arr[i][3].substr(0,module);
        }

        if(music.includes(m)&&checkTime<=Time) {
            if(checkTime<Time)answer.unshift(arr[i][2]);
            checkTime=Time;
        }
    }
    if(answer.length===0) answer.push('(None)');

    return answer[0];
}
