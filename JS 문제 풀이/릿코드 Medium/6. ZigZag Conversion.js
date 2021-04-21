/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if(numRows===1) return s;
    // 1. 2차원 배열 만들기
    let arr = new Array(numRows).fill(null).map(()=>new Array(s.length).fill(''));

    // 2. 2차원 배열에 s의 각 값 입력하기
    let idx=0;
    let row=0,col=0;
    while(true){
        while(row!==numRows) { if(idx===s.length) break; arr[row++][col]=s[idx++];}
        row--; col++;
        while(row>0) {
            if(idx===s.length) break;
            arr[--row][col++]=s[idx++];
        }
        row ++; col--;
        if(idx===s.length) break;

    }
    let answer='';

    for(let i=0;i<arr.length;i++){
        answer+=arr[i].join('');
    }
    return answer;
};

/*
단순 구현
*/
