function solution(key, lock) {
    let answer = false;
    let n=lock.length;
    let m=key.length;
    let ans = 0;
    /*
        lock을 3배 늘려 새로운 arr_lock을 만든다 (부분적으로 확인하기 위해)
        lock의 다른 모든 부분은 -1으로 초기화 해준다.
        이때 lock의 구멍부분은 ans로 체크해둔다(구멍부분을 전부 막는 경우를 확인하기 위해)
    */

    let arr_lock = new Array(n*3).fill(null).map(()=>new Array(n*3).fill(-1));
    for(let i=n;i<2*n;i++){
        for(let j=n;j<2*n;j++){
            arr_lock[i][j]=lock[i-n][j-n];
            if(arr_lock[i][j]===0) ans++;
        }
    }

    /*
        key를 총 4번 회전해서 각각 움직여본다.
        해당 key를 새로 만든 arr_lock 전부 움직여보며 확인한다.
    */

    /* 배열 회전 함수 */
    const cycle_key = function(arr){
        let tmp = [];
        for(let i=0;i<arr.length;i++){
            let arr_tmp=[];
            for(let j=arr.length-1;j>=0;j--){
                arr_tmp.push(arr[j][i]);
            }
            tmp.push(arr_tmp);
        }
        return tmp;
    }

    /* key와 lock을 매치시키는 함수 */
    const matchKey=function(key,lock){

        /* lock의 사이즈-key의 사이즈 만큼만 탐색(범위를 벗어나지 않게 탐색)*/
        for(let i=0;i<lock.length-m;i++){
            for(let j=0;j<lock.length-m;j++){
                let check=0; // key와 lock이 match 횟수 체크

                for(let a=0;a<key.length;a++){
                    for(let b=0;b<key.length;b++){

                        if(key[a][b] === 1){ // key가 돌기 부분인 경우
                            if(lock[i+a][j+b]===0) check++; // 해당 key 부분과 맞닿은 곳이 구멍 일 경우
                            else if(lock[i+a][j+b]===1) check--; // 해당 key 부분과 맞닿은 곳이 돌기 일 경우
                        }
                    }
                }

                if(check===ans) return true; // 구멍의 개수 만큼 match된 경우 true;
            }
        }
        return false;
    }

    for(let i=0;i<4;i++){
        if(matchKey(key,arr_lock)){ // match 성공시 true 반환
            return true;
        }

        key=cycle_key(key); // 열쇠 회전
    }

    return false;
}

/*
자물쇠는 격자 한 칸의 크기가 1x1인 nxn크기의 정사각형
열쇠는 mxm크기의 정사각 격자 => 회전과 이동이 가능

*/
