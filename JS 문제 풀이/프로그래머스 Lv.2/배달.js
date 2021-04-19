function solution(N, road, K) {
    let answer = 0;
    let arr,i;
    let Dist = new Array(N+1).fill(987654321);

    let vertex = new Array(N+1).fill(null).map(()=>new Array());

    for(i=0;i<road.length;i++){
        arr=road[i];
        vertex[arr[0]].push([arr[1], arr[2]]);
        vertex[arr[1]].push([arr[0], arr[2]]);
    }

    const Dijkstra = function (start){
        let pq = [];
        pq.push([start,0]);
        Dist[start]=0;

        while(pq.length !== 0){
            arr = pq.shift();
            let cost = arr[1];
            let cur = arr[0];

            for(i=0;i<vertex[cur].length;i++){
                arr = vertex[cur][i];
                let ncost = arr[1];
                let next = arr[0];

                if(Dist[next]>cost+ncost){
                    Dist[next]=cost+ncost;

                    pq.push([next,Dist[next]]);
                    pq.sort(function(a,b){
                        if(a[1]<b[1]) return -1;
                        if(a[1]===b[1]) return 0;
                        if(a[1]>b[1]) return 1;
                    })
                }
            }
        }
    }

    Dijkstra(1);
    for(i=1;i<=N;i++){
        if(Dist[i]<=K)answer++;
    }
    return answer;
}

/*
N개의 마을 , K시간 이하로 배달 가능한 마을, 양방향 도로(걸리는 시간이 다르다)
다익스트라
*/
