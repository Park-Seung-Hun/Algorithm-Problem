function solution(expression) {
    let answer = 0;
    let op = [];

    if(expression.includes('+')) op.push('+');
    if(expression.includes('-')) op.push('-');
    if(expression.includes('*')) op.push('*');

    let num = expression.split(/[^0-9]/);
    let tmp = expression.split('').filter(function(a){
     if(!(a>='0'&&a<='9')) return a
    });


    const getPermutations= function (arr, selectNumber) {
      const results = [];
      if (selectNumber === 1) return arr.map((value) => [value]);

      arr.forEach((fixed, index, origin) => {
        const rest = [...origin.slice(0, index), ...origin.slice(index+1)]
        const permutations = getPermutations(rest, selectNumber - 1);
        const attached = permutations.map((permutation) => [fixed, ...permutation]);
        results.push(...attached);
      });

      return results;
    };

    op = getPermutations(op,op.length);

    for(let i=0;i<op.length;i++){ // 연산자 경우의 수 만큼
        let arr = [...tmp];
        let cmp = [...num];

        for(let j=0;j<op[i].length;j++){ // 우선순위 연산자
            let p = op[i][j];
            let check = [];
            let save=[];

            for(let k=0;k<arr.length;k++){ // 식에 있는 연산자
                let first = parseInt(cmp.shift());
                let second = parseInt(cmp.shift());

                if(arr[k]===p){
                    if(p==='+'){
                        cmp.unshift(String(first+second));
                    }
                    else if(p==='-'){
                        cmp.unshift(String(first-second));
                    }
                    else if(p==='*'){
                        cmp.unshift(String(first*second));
                    }
                    check.push(arr[k]);
                }
                else {
                    cmp.unshift(String(second));
                    save.push(String(first));
                }
            }
            while(cmp.length!==0) save.push(cmp.shift());
            cmp=save;
            for(let input of check) {
                let idx = arr.indexOf(input);
                arr.splice(idx,1);
            }
        }
        let ans = Math.abs(parseInt(cmp[0]));
        if(answer<ans)answer=ans;
    }
    return answer;
}

// + , - , *연산
