코딩 테스트 대비 JavaScript
================
# 목차
- [배열과 메서드](#배열과-메서드)
  - [요소 추가,제거 메서드](#요소-추가,제거-메서드): splice, slice, concat
  - [forEach 반복작업](#forEach-반복작업)
  - [배열 탐색](#배열-탐색): indexOf, lastIndexOf, includes, find, filter
  - [배열 변형 메서드](#배열-변형-메서드): map, sort, reverse, split, join
  - [Array isArray](#Array-isArray)
  - [배열 메서드와 thisArg](#배열-메서드와-thisArg)

### 배열과 메서드
#### 요소 추가,제거 메서드

- `arr.splice(start,num)`: 배열에서 요소를 지우는 동작 (요소를 지우고 해당 요소의 자리를 채워준다.)
```node
let arr = ["I", "study", "JavaScript", "right", "now"];

// 처음(0) 세 개(3)의 요소를 지우고, 이 자리를 다른 요소로 대체합니다.
let replace = arr.splice(0, 3, "Let's", "dance");

alert( replace ) // now ["Let's", "dance", "right", "now"]

// 처음 두 개의 요소를 삭제함
let removed = arr.splice(0, 2);

alert( removed ); // "I", "study" <-- 삭제된 요소로 구성된 배열
```

- `arr.slice(start,end)`: start부터 end까지 요소를 복사한 새로운 배열을 반환한다.
```node
let arr = ["t", "e", "s", "t"];

alert( arr.slice(1, 3) ); // e,s (인덱스가 1인 요소부터 인덱스가 3인 요소까지를 복사(인덱스가 3인 요소는 제외))

alert( arr.slice(-2) ); // s,t (인덱스가 -2인 요소부터 제일 끝 요소까지를 복사)
```

- `arr.concat(arg1,arg2)`: 기존 배열의 요소를 사용해 새로운 배열을 만들거나 기존 배열에 요소를 추가하고자 할 때 사용.
```node
et arr = [1, 2];

// arr의 요소 모두와 [3,4]의 요소 모두를 한데 모은 새로운 배열이 만들어집니다.
alert( arr.concat([3, 4]) ); // 1,2,3,4

// arr의 요소 모두와 [3,4]의 요소 모두, [5,6]의 요소 모두를 모은 새로운 배열이 만들어집니다.
alert( arr.concat([3, 4], [5, 6]) ); // 1,2,3,4,5,6

// arr의 요소 모두와 [3,4]의 요소 모두, 5와 6을 한데 모은 새로운 배열이 만들어집니다.
alert( arr.concat([3, 4], 5, 6) ); // 1,2,3,4,5,6
```

[😊목차 가기](#목차)


#### forEach 반복작업
- `arr.forEach(function)`: 주어진 함수를 배열 요소에 각각에 대해 실행
```node
arr.forEach(function(item, index, array) {
  // 요소에 무언가를 할 수 있습니다.
});

["Bilbo", "Gandalf", "Nazgul"].forEach((item, index, array) => {
  alert(`${item} is at index ${index} in ${array}`);
});
```

[😊목차 가기](#목차)


#### 배열 탐색
1. 배열 내에서 무언가를 찾을 때 쓰는 메서드
- `arr.indexOf(item,from)`: from부터 시작해 item을 찾는다. 요소 발견시 index 반환, 발견 못할 시 -1 반환
- `arr.lastIndexOf(item,from)`: 뒤에서 앞으로 시작
- `arr.includes(item,from)`: from부터 시작해 item이 있는지 검색하고, 해당 요소 발견시 true
```node
let arr = [1, 0, false];

alert( arr.indexOf(0) ); // 1
alert( arr.indexOf(false) ); // 2
alert( arr.indexOf(null) ); // -1

alert( arr.includes(1) ); // true
```
2. 객체로 이루어진 배열 내에서 무언가를 찾을 때 쓰는 메서드
- `arr.find(function(item,index,array))`
  - item: 함수를 호출할 요소
  - index: 요소의 인덱스
  - array: 배열 자기 자신
```node
let result = arr.find(function(item, index, array) {
  // true가 반환되면 반복이 멈추고 해당 요소를 반환합니다.
  // 조건에 해당하는 요소가 없으면 undefined를 반환합니다.
});

// 예시
let users = [
  {id: 1, name: "John"},
  {id: 2, name: "Pete"},
  {id: 3, name: "Mary"}
];

let user = users.find(item => item.id == 1);

alert(user.name); // John
```
- `arr.filter(fuction(item,index,array))`: 요소 전체를 담은 배열을 반환한다.
```node
let results = arr.filter(function(item, index, array) {
  // 조건을 충족하는 요소는 results에 순차적으로 더해집니다.
  // 조건을 충족하는 요소가 하나도 없으면 빈 배열이 반환됩니다.
});

// 예시

let users = [
  {id: 1, name: "John"},
  {id: 2, name: "Pete"},
  {id: 3, name: "Mary"}
];

// 앞쪽 사용자 두 명을 반환합니다.
let someUsers = users.filter(item => item.id < 3);

alert(someUsers.length); // 2
```

[😊목차 가기](#목차)

#### 배열 변형 메서드
- `arr.map()`: 배열 오소 전체를 대상으로 함수를 호출하고, 호출 결과를 배열로 반환.
```node
let result = arr.map(function(item, index, array) {
  // 요소 대신 새로운 값을 반환합니다.
});

let lengths = ["Bilbo", "Gandalf", "Nazgul"].map(item => item.length);
alert(lengths); // 5,7,6
```

- `arr.sort(fn)`: 배열의 요소를 정렬해준다.
```node
function compareNumeric(a, b) {
  if (a > b) return 1;
  if (a == b) return 0;
  if (a < b) return -1;
}

let arr = [ 1, 2, 15 ];

// arr 내부가 재 정렬됩니다.(문자열로 취급되어 재 졍렬되므로 배열 비교 함수를 만들어준다.)
arr.sort(compareNumeric);

alert( arr );  // 1, 2, 15
```

- `arr.reverse()`: 배열의 요소를 역순으로 정렬시켜주는 메서드
```node
let arr = [1, 2, 3, 4, 5];
arr.reverse();

alert( arr ); // 5,4,3,2,1
```
- `str.split(delim)`: delim을 기준으로 문자열을 쪼개고 배열로 반환한다.
```node
// 1. 문자열 글자 단위 분리
let str = "test";
alert( str.split('') ); // t,e,s,t

// 2. 문자열을 원하는 갯수 만큼 쪼개서 반환
let arr = 'Bilbo, Gandalf, Nazgul, Saruman'.split(', ', 2);
alert(arr); // [Bilbo, Gandalf]
```
- `arr.join(glue)`: 배열 요소 모두를 glue를 사용해 하나의 문자열로 합친다.
```node
let arr = ['Bilbo', 'Gandalf', 'Nazgul'];

let str = arr.join(';'); // 배열 요소 모두를 ;를 사용해 하나의 문자열로 합칩니다.

alert( str ); // Bilbo;Gandalf;Nazgul
``` 
[😊목차 가기](#목차)

#### Array isArray
```node
alert(Array.isArray({})); // false

alert(Array.isArray([])); // true
```

[😊목차 가기](#목차)

#### 배열 메서드와 thisArg
: 


[😊목차 가기](#목차)
