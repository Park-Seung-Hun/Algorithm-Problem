function solution(m, n, board) {
    let answer = 0;
    let i,j;
    let box = [];
    for(i=0;i<m;i++){
        box.push(board[i].split(''));
    }

    while(true) {
        let ans = false;
        let check=[];

        for(i=0;i<m;i++){
            let tmp = Array.from({length: n},()=>false);
            check.push(tmp);
        }



    // 1. box의 각 블록마다 체크하기 (4개가 다 같은 블록이면 check[i][j]=true)
        for(i=0;i<m-1;i++){
            for(j=0;j<n-1;j++){
                 if(box[i][j]!=='#'&&box[i][j]===box[i+1][j]&&box[i][j]===box[i][j+1]&&box[i][j]===box[i+1][j+1]){
                     check[i][j]=check[i][j+1]=check[i+1][j]=check[i+1][j+1]=true;
                     ans=true;
                 }
            }
        }
        if(!ans) break; // 더이상 없어진 블록이 없으면 제거

    // 2. box의 check[i][j]=true인 곳 다 지우기 '#'
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(check[i][j]){
                    answer++;
                    box[i][j]='#';
                }
            }
        }

    // 3. board의 '#'인 부분이 없어질 때 까지 내리기
        for(i=0;i<n;i++){
            for(j=m-2;j>=0;j--){
                if(box[j][i]!=='#'&&box[j+1][i]==='#'){
                    let idx = j;
                    while(true){
                        let doll = box[idx][i];
                        if(idx===m-1||box[idx+1][i]!=='#') break;
                        box[idx+1][i]=doll;
                        box[idx][i]='#';
                        idx++;
                    }
                }
            }
        }

    }




    // 4. 1번부터 반복해서 체크된 곳이 없으면 ( ans =true; ) break;
    return answer;
}
