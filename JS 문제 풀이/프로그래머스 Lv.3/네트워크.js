
function solution(n, computers) {
    let answer = 0;
    let edge = new Array(n);

    // 1. BFS를 위한 node 값 저장
    for(let i=0;i<computers.length;i++){
        let edge_=[];

        for(let j=0;j<computers[i].length;j++){
            if(i!==j&&computers[i][j]===1) edge_.push(j);
        }

        edge[i]=edge_;
    }

    console.log(edge);
    // 2. BFS 정의
    let visited = Array.from({length:n},()=>false);
    const bfs = function(cur){
        let queue = [];
        queue.push(cur);

        while(queue.length!==0){
            let here = queue.shift();

            for(let i=0;i<edge[here].length;i++){
                let there = edge[here][i];
                if(visited[there]) continue;
                visited[there]=true;
                queue.push(there);
            }
        }
    }

    for(let i=0;i<n;i++){
        if(visited[i]===false){
            answer++;
            bfs(i);
        }
    }
    return answer;
}
