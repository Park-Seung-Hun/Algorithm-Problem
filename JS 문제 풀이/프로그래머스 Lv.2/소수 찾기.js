function getPermutations (arr, selectNumber) {
  const results = [];
  if (selectNumber === 1) return arr.map((value) => [value]); // 1개씩 택할 때, 바로 모든 배열의 원소 return

  arr.forEach((fixed, index, origin) => {
    const rest = [...origin.slice(0, index), ...origin.slice(index+1)] // 해당하는 fixed를 제외한 나머지 배열
    const permutations = getPermutations(rest, selectNumber - 1); // 나머지에 대해 순열을 구한다.
    const attached = permutations.map((permutation) => [fixed, ...permutation]); // 돌아온 순열에 대해 떼 놓은(fixed) 값 붙이기
    results.push(...attached); // 배열 spread syntax 로 모두다 push
  });

  return results; // 결과 담긴 results return
}

function solution(numbers) {
    let answer = 0;
    let arr = numbers.split('');
    let map = new Map();
    let ans;
    let prime = [];

    for(let i=1;i<=numbers.length;i++){
        ans = getPermutations (arr,i);

        for(let j=0;j<ans.length;j++){
            if(!map.has(parseInt(ans[j].join('')))){
                map.set(parseInt(ans[j].join('')),true);
                prime.push(parseInt(ans[j].join('')));
                prime.sort(function (a,b){
                    return a-b;
                });
            }
        }
    }

    let check=Array.from({length: prime[prime.length-1]+1}, ()=>false);

    check[0]=check[1]=true;
    for(let i=2;i<=prime[prime.length-1];i++){
        if(check[i]===false){
            for(let j=i+i;j<=prime[prime.length-1];j+=i) check[j]=true;
        }
    }
    for(let num of prime) {
        if(check[num]===false) answer++;
    }
    return answer;
}
