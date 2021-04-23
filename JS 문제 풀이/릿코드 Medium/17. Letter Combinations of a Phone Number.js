/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if(digits.length===0) return [];

    let save = ['','','abc','def','ghi','jkl','mno','pqrs','tuv','wxyz'];
    let arr = digits.split('').map(Number);

    let tmp =[];
    for(let num of arr) tmp.push(save[num].split(''));

    console.log(tmp);
    let answer=[''];

    let idx=0;
    while(true){
        if(idx===tmp.length) break;

        let ans=[];
        for(let i=0;i<answer.length;i++){
            let char = answer[i];
            for(let j=0;j<tmp[idx].length;j++){
                ans.push(char+tmp[idx][j]);
            }
        }
        answer=ans;
        idx++;
    }

    return answer;
};

/*
단순 문자열 구현.
*/
