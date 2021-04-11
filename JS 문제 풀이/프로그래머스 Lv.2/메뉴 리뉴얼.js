function solution(orders, course) {
    var answer = [];

    /* 조합을 구하는 함수 */
    const getCombinations = function (arr, selectNumber) {
      const results = [];
      if (selectNumber === 1) return arr.map((value) => [value]);

      arr.forEach((fixed, index, origin) => {
        const rest = origin.slice(index + 1);
        const combinations = getCombinations(rest, selectNumber - 1);
        const attached = combinations.map((combination) => [fixed, ...combination]);
        results.push(...attached);
      });

      return results;
    }

    /* orders를 course에 따라 조합을 만든다. */
    for(let c of course){
        const comb_result = {};
        let max = 0;

        for(let order of orders){
            const order_arr = order.split('').sort();
            const result = getCombinations(order_arr,c);
            /* 조합의 결과 */
            for(let comb of result){
                const tmp = comb.join('');

                if(tmp in comb_result) {
                    comb_result[tmp]++;
                }
                else comb_result[tmp]=1;

                if(comb_result[tmp]>max) max=comb_result[tmp];
            }
        }

        for(let key in comb_result){
            if(comb_result[key]===max&&max>=2) answer.push(key);
        }
    }
    console.log(answer.sort());

    return answer;
}

/*
풀이.
(순서가 다른 조합이 발생활 수도 있으므로 우선 order를 정렬한다.)
1. course의 값을 r로 두고 nCr을 전부 구한다. => 단품메뉴 조합
2. 각 단품메뉴 조합을 객체를 통해 값을 준다 (이때 최대 값도 구함)
3. 최대 값에 해당하는 단품메뉴 조합만 건진다.
*/
