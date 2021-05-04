function solution(n, t, m, timetable) {
    let answer = '';
    /* 콘이 무사히 탈 수 있는 최대한 늦은 버스 시간 구하기 */

    /* 버스 시간 만들기 & 크루원의 도착 시간 정리 */
    let bus = []; // 버스 시간 배열
    let line = {}; // 줄 선 크루원 시간 객체 (C++의 map)
    timetable.sort(); // 크루원 오름차순 정리

    let idx=0;
    for(let i=0;i<n;i++){
        let busTime=540+i*t;
        // 버스 시간의 객체 생성
        bus.push(busTime);
        line[busTime]=[];

        for(let j=idx;j<timetable.length;j++){
            let arr = timetable[j].split(":");
            let crewtime=parseInt(arr[0])*60+parseInt(arr[1]);

            // 버스 시간대의 줄이 총 인원 m을 넘지 않고, 크루의 시간이 버스 시간보다 작거나 같은경우 => 줄세운다.
            if (line[busTime].length < m && crewtime <= busTime) line[busTime].push(crewtime);
            else { // 다음 버스를 부른다.
                idx = j;
                break;
            }
        }
    }

    /*
        1. 맨 끝에 꽉찬 버스가 여러대인 경우 => 꽉찬 버스 중 가장 빠른 버스의 가장 뒤에 줄선 사람의 -1분
        2. 꽉찬 버스가 없는 경우 => 가장 늦은 시간대의 버스 시간
    */


    while(bus.length){
        let bus_=bus.shift();

        if (line[bus_].length < m) answer = bus_; // 버스 시간대에 줄이 덜 채워진 경우 => 콘이 버스 시간에 도착하면 된다.
        else answer = line[bus_][line[bus_].length - 1]-1; // 버스 시간대에 줄이 채워진 경우 => 콘이 버스 줄 맨 뒤의 사람보다 1분 더 일찍 와야한다.
    }

    // 시간으로 바꿔주는 과정.
    let min = answer%60;
    if(min<10) min= '0'+min.toString();
    else min=min.toString();

    let hour = parseInt(answer/60);
    if(hour<10) hour= '0'+hour.toString();
    else hour=hour.toString();

    return hour+':'+min;
}
