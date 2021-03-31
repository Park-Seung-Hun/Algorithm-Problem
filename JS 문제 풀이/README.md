# JavaScript 코딩 테스트 준비

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


### 배열
1. `arr.reverse()` => 배열을 뒤집은 배열로 만든다.
2. `arr.join('')` => 배열을 각 요소마다 합쳐 문자열로 만든다.
3. 배열 초기화

```node
Array.from({length : 길이}, ()=> 원하는 값 ) => 배열을 원하는 값으로 초기
Array.from({length: 5}, (undefined, i) => i); => i(index) 1씩 증가
```
4. 배열의 정렬함수

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

5. 배열의 최대 최소
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
