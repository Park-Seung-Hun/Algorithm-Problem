function solution(n, s, a, b, fares) {
    let answer = 987654321;
    let i,arr;
    /*
        합승 택시 요금 최소 구하기
        특정 지점 까지 합승 + 특정 지점에서 A까지 + 특정 지점에서 B까지 요금이 최소인 경우 구하기.
        플로이드 와샬로 각 구간에 대한 요금을 구한후 min[(s,t)+(t,a)+(t,b)] 구하기
    */

    /* 각 노드에 대한 경로 값 */
    /* 연결된 거리 정보를 저장하는 vertex와 초기화*/
    let vertex = new Array(n+1).fill(null).map(()=>new Array(n+1).fill(987654321));
    for(i=0;i<fares.length;i++){
        arr=fares[i];
        vertex[arr[0]][arr[1]] = arr[2];
        vertex[arr[1]][arr[0]] = arr[2];
    }
    for(i=0;i<=n;i++) vertex[i][i]=0;

    const floyd_warwhall = function(){
        for(let k=1;k<=n;k++){
            for(let i=1;i<=n;i++){
                for(let j=1;j<=n;j++){
                    if(vertex[i][k]===987654321||vertex[k][j]===987654321) continue;

                    if(vertex[i][j]>vertex[i][k]+vertex[k][j]) vertex[i][j]=vertex[i][k]+vertex[k][j];
                }
            }
        }

    }
    floyd_warwhall();

    for(i=1;i<=n;i++){
        answer = Math.min(answer,vertex[s][i]+vertex[i][a]+vertex[i][b]);
    }
    return answer;
}
