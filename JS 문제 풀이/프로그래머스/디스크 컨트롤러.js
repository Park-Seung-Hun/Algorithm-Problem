function solution(jobs) {
    let answer = 0,idx=0,time=0;
    let priority_queue = [] ;

    // 1. 요청 시간 순으로 정렬
    jobs.sort(function (a,b){
        if(a[0]<b[0]) return -1;
        if(a[0]===b[0]) return 0;
        if(a[0]>b[0])return 1;
    })

    // 2. 우선순위 큐를 이용해 요청부터 종료까지의 시점에 들어온 작업은 처리 시간순으로 정렬해준다.
    while(idx < jobs.length || priority_queue.length !==0 ){
        if(idx<jobs.length && time >= jobs[idx][0]){ // 현재 시간이 작업의 대기 시간보다 커질 때
            priority_queue.push(jobs[idx++]);
            priority_queue.sort(function (a,b){ // 작업 시간이 더 적은 순으로 정렬
                return a[1]-b[1];
            });
            continue;
        }
        if(priority_queue.length!==0){ // 우선순위 큐에 작업이 대기하고 있는 경우
            time+=priority_queue[0][1];
            answer += time -priority_queue[0][0];
            priority_queue.shift();
        }else{ // 우선순위 큐에 작업이 대기하지 않는 경우
            time = jobs[idx][0];
        }
    }
    return parseInt(answer / jobs.length);
}
