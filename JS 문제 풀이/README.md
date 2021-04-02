# JavaScript 코딩 테스트 준비
  - [문자열](#문자열)
  - [배열](#배열)
  - [우선순위큐](#우선순위-큐)
  - [순열과 조합](#순열과-조합)
1. includes(item): item이 존재하는지 안하는지 확인한다.

### 문자열
1. `str.split('')` => 문자열을 나눠 배열로 만든다.
2. `parseInt(str, 진법)` => 해당 진법으로 표현된 문자열을 10진법으로 만든다.
3. `toString(진법)`
```node
let value = 120;
console.log(vale.toString(3)); // 11110 => 10진법 수를 해당 진법 문자열로 만든다.
```
4. `str.substr(시작 지점,길이`): 시작 지점에서 길이만큼 반환
5. `str.slice(시작 지점,끝나는 지점)`: 시작 지점에서 끝
6. `str.charCodeAt(idx)` => 문자열에서 idx에 있는 문자의 아스키 코드 출력
7. `String.fromCharCode(아스키 코드)` => 아스키 코드를 문자로 바꿔준다.
8. 문자열 뒤에 문자열 추가: `str+= str1;`, 앞에 문자열 추가: `str = str1 + str; `
9. 모든 문자 대문자 `str.toUpperCase()`, 소문자 `str.toLowerCase()`

[위로 가기](#top)


### 배열
1. `arr.reverse()` => 배열을 뒤집은 배열로 만든다.
2. `arr.join('')` => 배열을 각 요소마다 합쳐 문자열로 만든다.
3. `arr.map(변수 => 변수 조건)` => map 내부에 String, Number을 넣으면 배열 요소들이 해당 Type으로 변환.(문자열 배열 -> 숫자 배열)
4. `arr.filter(fuction)`: 메서드는 주어진 함수의 테스트를 통과하는 모든 요소를 모아 새로운 배열을 반환
5. 2차원 배열을 취급할 땐 조건문에 바로 값을 넣지 말자!!(ex) 프린터)
6. 배열 초기화
```node
Array.from({length : 길이}, ()=> 원하는 값 ) => 배열을 원하는 값으로 초기
Array.from({length: 5}, (undefined, i) => i); => i(index) 1씩 증가
```
7. 배열의 정렬함수

```node
정렬 함수 Tip.
이 함수가 a, b 두개의 element를 파라미터로 입력받을 경우,
이 함수가 리턴하는 값이 0보다 작을 경우,  a가 b보다 앞에 오도록 정렬하고,
이 함수가 리턴하는 값이 0보다 클 경우, b가 a보다 앞에 오도록 정렬합니다.
만약 0을 리턴하면, a와 b의 순서를 변경하지 않습니다.
```
- 정렬함수 `오름차순`

```node
function compareNum(a,b){
    if(a<b) return -1;
    if(a===b)return 0;
    if(a>b)return 1;
}
```

- 정렬함수 `내림차순`

```node
function compare(a,b){
    if(a<b) return 1;
    if(a==b)return 0;
    if(a>b) return -1;
}
```
- `문자열 정렬함수`

```node
if(f===s) return (a>b) - (a<b) => a>b이면 1 , a<b이면 -1 반환
else return (f>s) - (f<s); => 마찬가지로 f>s이면 1, f<s이면 -1 반환 (일반 정렬과 같다.)
```

8. 배열의 최대 최소
- 배열의 `최대 값`

```node
Math.max.apply(null,arr)

// 배열의 크기가 ~10^7 이상이 될 경우
var max = array.reduce( function (previous, current) {
	return previous > current ? previous:current;
});
```

- 배열의 `최소 값`

```node
 Math.min.apply(null,arr)

// 배열의 크기가 ~10^7 이상이 될 경우
var min = array.reduce( function (previous, current) {
	return previous > current ? current:previous;
});
```


### 우선순위 큐
```node
let item;
priority_queue.push(item);
priority_queue.sort(function (a,b){
    // return a-b; : 최소 힙
    // return b-a; : 최대 힙
});
```

### 순열과 조합
- 조합
  - 순서가 바뀌어도 하나의 조합으로 생각한다.

```node
const getCombinations = function (arr, selectNumber) {
  const results = [];
  if (selectNumber === 1) return arr.map((value) => [value]); // 1개씩 택할 때, 바로 모든 배열의 원소 return

  arr.forEach((fixed, index, origin) => {
    const rest = origin.slice(index + 1); // 해당하는 fixed를 제외한 나머지 뒤
    const combinations = getCombinations(rest, selectNumber - 1); // 나머지에 대해서 조합을 구한다.
    const attached = combinations.map((combination) => [fixed, ...combination]); //  돌아온 조합에 떼 놓은(fixed) 값 붙이기
    results.push(...attached); // 배열 spread syntax 로 모두다 push
  });

  return results; // 결과 담긴 results return
}

const example = [1,2,3,4];
const result = getCombinations(example, 3); // 4C3
/*
Input: [1, 2, 3, 4]
Output: [ [1, 2, 3], [1, 2, 4], [1, 3, 4], [2, 3, 4] ]
*/
```

- 순열
  - 순서가 바뀌면 다른 순열이다.

```node
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

const example = [1,2,3,4];
const result = getPermutations(example, 3); //
console.log(result);
// => [
//   [ 1, 2, 3 ], [ 1, 2, 4 ],
//   [ 1, 3, 2 ], [ 1, 3, 4 ],
//   [ 1, 4, 2 ], [ 1, 4, 3 ],
//   [ 2, 1, 3 ], [ 2, 1, 4 ],
//   [ 2, 3, 1 ], [ 2, 3, 4 ],
//   [ 2, 4, 1 ], [ 2, 4, 3 ],
//   [ 3, 1, 2 ], [ 3, 1, 4 ],
//   [ 3, 2, 1 ], [ 3, 2, 4 ],
//   [ 3, 4, 1 ], [ 3, 4, 2 ],
//   [ 4, 1, 2 ], [ 4, 1, 3 ],
//   [ 4, 2, 1 ], [ 4, 2, 3 ],
//   [ 4, 3, 1 ], [ 4, 3, 2 ]
// ]
```
