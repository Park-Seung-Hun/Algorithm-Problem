function solution(expression) {
    let answer = 0;
    let op = [];

    /* 수식이 존재하는지 찾기 */
    if(expression.includes('+')) op.push('+');
    if(expression.includes('-')) op.push('-');
    if(expression.includes('*')) op.push('*');

    /* 존재하는 수식 우선순위 정하기 */
    const getPermutations= function (arr, selectNumber) {
      const results = [];
      if (selectNumber === 1) return arr.map((value) => [value]); // 1개씩 택할 때, 바로 모든 배열의 원소 return

      arr.forEach((fixed, index, origin) => {
        const rest = [...origin.slice(0, index), ...origin.slice(index+1)] // 해당하는 fixed를 제외한 나머지 배열
        const permutations = getPermutations(rest, selectNumber - 1); // 나머지에 대해 순열을 구한다.
        const attached = permutations.map((permutation) => [fixed, ...permutation]); // 돌아온 순열에 대해 떼 놓은(fixed) 값 붙이기
        results.push(...attached); // 배열 spread syntax 로 모두다 push
      });

      return results; // 결과 담긴 results return
    };

    let results = getPermutations(op,op.length);

    /* 우선순위에 따라 계산 실시*/
    for(let result of results){
        let num = expression.split(/[^0-9]/).map(Number);
        let ope = expression.split(/[0-9]/).filter(a=> a!=='');

        for(let o of result){
            /* o = 연산자 */
            let tmp = [];
            let tmp_num = [num[0]];
            let len = ope.length;

            for(let i=0;i<len;i++){
                let ope_t=ope.shift();
                if(ope_t===o){
                    let a = tmp_num.pop();

                    if(o==='+'){
                        tmp_num.push(a+num[i+1]);
                    }
                    if(o==='-'){
                        tmp_num.push(a-num[i+1]);
                    }
                    if(o==='*'){
                        tmp_num.push(a*num[i+1]);
                    }
                }
                else{
                    tmp_num.push(num[i+1]);
                    tmp.push(ope_t);
                }
            }
            ope=[...tmp];
            num=[...tmp_num];
        }
        if(Math.abs(num[0])>answer) answer = Math.abs(num[0]);
    }

    return answer;
}

// + , - , *연산
