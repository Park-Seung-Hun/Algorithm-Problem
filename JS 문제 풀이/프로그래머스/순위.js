function solution(n, results) {
    let answer = 0;
    let win = new Array(n+1);
    for(let i=0;i<=n;i++) win[i]=Array.from({length:n+1},()=>0);

    // win[a][b]=> a가 b에게 승리.
    for(let i=0;i<results.length;i++){
        let a = results[i][0];
        let b = results[i][1];
        win[a][b]=1;
    }

    // 승패 측정을 위한 플로이드 와샬
    for(let k=1;k<=n;k++){
        for(let i=1;i<=n;i++){
             for(let j=1;j<=n;j++){
                if(win[i][k]===1&&win[k][j]===1) win[i][j]=1;
            }
        }
    }

    // 자기 자신의 순위를 알기 위해선 나를 제외한 나머지 상대와의 승패를 알아야 한다.
    for(let i=1;i<=n;i++){
        let cnt=0;
        for(let j=1;j<=n;j++){
            if(win[i][j]===1 || win[j][i]===1) cnt++;
        }
        if(cnt===n-1)answer++;
    }
    return answer;
}
