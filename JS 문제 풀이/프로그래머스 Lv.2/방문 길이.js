function solution(dirs) {
    let answer = 0;

    // 1. 방문 배열 설정
    let visited = {};
    let x = 5,y = 5;
    // 2. dirs만큼 움직이기
    let dx=0,dy=0;
    for(let i=0;i<dirs.length;i++){
        if(dirs[i]==='U'){
            dx=-1;
        }
        else if(dirs[i]==='D'){
            dx=1;
        }
        else if(dirs[i]==='R'){
            dy=1;
        }
        else if(dirs[i]==='L'){
            dy=-1;
        }

        // 범위를 벗어나는 경우 다음 명령어를 찾는다.
        if(x+dx<0||x+dx>10||y+dy<0||y+dy>10) {
            dx=0;dy=0;
            continue;
        }

        // 범위를 벗어나지 않는 경우
        let str1 = [x,y,x+dx,y+dy].join('');
        let str2 = [x+dx,y+dy,x,y].join('');

        if(!(str1 in visited)&&!(str2 in visited)){
            answer++;
            visited[str1]=true;
            visited[str2]=true;
        }
        x+=dx;y+=dy;
        dx=0;dy=0;
    }
    return answer;
}
