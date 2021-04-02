function solution(n, edge) {
    let answer = 0;
    let vertex = new Array(n+1);
    let max = 0;

    for(let i=0;i<=n;i++) vertex[i]=[];
    for(let i=0;i<edge.length;i++){
        let from = edge[i][0];
        let to = edge[i][1];

        vertex[from].push(to);
        vertex[to].push(from);
    }


    let Dist = Array.from({length:n+1},()=> 987654321);
    const Dijkstra = function(start){
        let pq = [];
        pq.push([1,start]);
        Dist[start]=0;

        while(pq.length!==0){
            let pq_tmp=pq.shift()
            let cost = pq_tmp[0];
            let cur = pq_tmp[1];

            if(cost>max) max=cost;

            for(let i=0;i<vertex[cur].length;i++){
                let next = vertex[cur][i];
                let ncost = 1;

                if(Dist[next]>cost+ncost){
                    Dist[next] = cost+ncost;
                    pq.push([Dist[next],next]);
                    pq.sort(function (a,b){
                        if(a[0]<b[0]) return -1;
                        if(a[0]===b[0]) return 0;
                        if(a[0]>b[0]) return 1;
                    });
                }
            }
        }
    }

    Dijkstra(1);
    for(let i=1;i<=n;i++) {
        if(Dist[i]===max)answer++;
    }
    return answer;
}
