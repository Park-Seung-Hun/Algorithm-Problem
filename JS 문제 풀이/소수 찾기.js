function isPrime(num){
    let cnt=0;
    const arr = Array.from({length: num+1}, () => false);

    for(let i=2;i<=num;i++){
        if(arr[i]===false){
            cnt++;

            for(let j=i;j<=num;j+=i) arr[j]=true;
        }
    }
    return cnt;
}
function solution(n) {
    var answer = 0;
    answer=isPrime(n);
    return answer;
}

/*
에라토스테네스의 체 구현.

Tip.
Array.from({length : 길이}, ()=> 원하는 값 ) => 배열을 원하는 값으로 초기
Array.from({length: 5}, (undefined, i) => i); => i(index) 1씩 증가
*/
