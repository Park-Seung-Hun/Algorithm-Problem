function solution(maps) {
    let answer = 0;
    let visited = [];
    let n = maps.length;
    let m =maps[0].length;

    for(let i=0;i<n;i++){
        visited.push(Array.from({length:m},()=>987654321));
    }

    const bfs = function(cx,cy){
        let queue = [];
        queue.push([cx,cy,1]);
        visited[cx][cy]=1;

        const dx = [0,0,1,-1];
        const dy = [1,-1,0,0];

        while(queue.length!==0){
            let arr = queue.shift();
            let hx = arr[0];
            let hy = arr[1];
            let cost = arr[2];

            for(let i=0;i<4;i++){
                let nx = hx+dx[i];
                let ny = hy+dy[i];

                if(!(nx>=0&&ny>=0&&nx<n&&ny<m)||maps[nx][ny]===0)continue;

                if(visited[nx][ny]>cost+1){
                    visited[nx][ny]=cost+1;
                    queue.push([nx,ny,cost+1]);
                }
            }
        }
    }

    bfs(0,0);

    if(visited[n-1][m-1]===987654321) return -1;
    return visited[n-1][m-1];
}


/*
단순 BFS를 이용하여 최단거리 구하기
*/
