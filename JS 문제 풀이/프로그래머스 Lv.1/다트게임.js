function solution(dartResult) {
    let answer = 0;
    let num='';
    let ans =[];
    for(let idx in dartResult){
        let char = dartResult[idx];

        if(char>='0'&&char<='9'){
            num+=char;
        }
        else {
            num=parseInt(num);
            let len = ans.length;

            if(char === 'S') ans.push(Math.pow(num,1));
            else if(char==='D') ans.push(Math.pow(num,2));
            else if(char==='T') ans.push(Math.pow(num,3));
            else if(char==='*'){
                if(ans.length===1){
                    ans[len-1]*=2;
                }
                else {
                    ans[len-1]*=2;
                    ans[len-2]*=2;
                }
            }
            else if(char==='#'){
                ans[len-1]*=-1;
            }
            num='';
        }
    }

   answer = ans.reduce(function add(sum, currValue) {
      return sum + currValue;
}, 0);
    return answer;
}

/*
S,D,T 1제곱 2제곱 3제곱
* 해당 점수와 바로 앞 점수를 각 2배 , # 해당 점수 -
*/
