function solution(n) {
    let answer = [];

    let arr =[];

    for(let i=0;i<n;i++){
        let tmp = Array.from({length: n }, ()=>0);
        arr.push(tmp);
    }

    let row=0;
    let col=0;
    let num=1;
    let check=0;
    if(n>3){
        while(true){
            while(row<n&&arr[row][col]===0) arr[row++][col]=num++; // 아래
            row--; col++;
            while(col<n&&arr[row][col]===0) arr[row][col++]=num++;
            col--;
            row--; col--;
            while(arr[row][col]===0) arr[row--][col--]=num++;
            row+=2;col++;

            if(check===num) break;
            else check=num;

        }
        for(let i=0;i<n;i++){
            for(let j=0;j<n;j++){
                if(arr[i][j]!==0) answer.push(arr[i][j]);
            }
        }
    }
    else {
        if(n===1) answer.push(1);
        else if(n===3) answer.push(1, 2, 6, 3, 4, 5);
        else answer.push(1,2,3);
    }

    return answer;
}
solution(4);

// 더 좋은 풀이를 원해 (n==1,2,3일때)
