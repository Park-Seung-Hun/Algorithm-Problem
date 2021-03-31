function compareNum(a,b){
    if(a<b) return 1;
    if(a===b) return 0;
    if(a>b) return -1;
}
function solution(priorities, location) {
    let answer = 0;
    let arr =[];

    for(let i=0;i< priorities.length;i++) arr.push([priorities[i],i]);

    priorities.sort(compareNum);

    while(true){
        let J = arr.shift();
        let priority = priorities.shift();
        let J_priority=J[0];
        let J_idx=J[1];

        if(J_priority===priority){
            answer++;
            if(J_idx===location) break;
        }
        else{ // 우선순위가 같지 않은 경우 // 우선순위가 같지 않은 경우
            priorities.unshift(priority);
            arr.push(J);
        }
    }
    return answer;
}
