function solution(brown, yellow) {
    let answer = [];
    let tot = brown+yellow;
    let row,col = 0;

    for(row = tot;row>=0;row--){
        if(tot%row!==0 || parseInt(tot/row) < 3 ) continue;// 나누어 떨어지지 않거나 3보다 작은 경우
        col=parseInt(tot/row);
        if((col-2)*(row-2)===yellow) break;
    }
    answer.push(row,col);
    return answer;
}

// 1. brown * yellow = > 전체 타일의 개수
// 2. 1부터 ~ 전체 타일의 개수까지
