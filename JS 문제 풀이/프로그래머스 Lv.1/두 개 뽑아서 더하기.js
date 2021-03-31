function compare(a,b){
    if(a>b) return 1;
    if(a==b)return 0;
    if(a<b) return -1;
}
function solution(numbers) {
    let answer = [];
    let map = new Map();
    for(let i=0;i<numbers.length-1;i++){
        for(let j=i+1;j<numbers.length;j++){
            let num = numbers[i]+numbers[j];
            if(map.get(num) !== true){
                map.set(num,true);
                answer.push(num);
            }
        }
    }
    answer.sort(compare);
    return answer;
}
// 주어진 배열 numbers에서 두개의 수를 꺼내 더한다(중복 x)
console.log(solution([2, 1, 3, 4, 1])); // 	[2, 3, 4, 5, 6, 7]
console.log(solution(	[5, 0, 2, 7])); // [2, 5, 7, 9, 12]

/*
sol. Map 객체를 선언하여 두개의 수를 더한 값 num에 대해
1. answer 객체에 들어가 있으면 true
2. 없으면 false를 입력해 중복을 제거한다.

**
가장 중요한 것. num 배열 sort시 compare 함수를 선언해 주지 않는다면,
요소들이 문자열로 취급되기 때문에 제대로 된 정렬을 할 수 없으므로 `compare`함수를 선언한다.
**
*/
