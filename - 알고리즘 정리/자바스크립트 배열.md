코딩 테스트 대비 JavaScript
================
# 목차
- [문자열](#문자열)
  - [배열 선언](#배열-선언)
  - [pop push shift unshift](#pop-push-shift-unshift)
  - [반복문](#반복문): 일반 반복문, for of, for in
  - [다차원 배열](#다차원-배열)
  - [toString](#toString)

### 배열
#### 배열 선언

```node
let arr = new Array(num); // 길이가 num인 배열 생성
let arr = [];

arr.length // 배열의 길이
arr.length = 0; // 배열을 비우는 방법

let arr = [ '사과', { name: '이보라' }, true, function() { alert('안녕하세요.'); } ]; // 자료형의 제약이 없다.
```

[😊목차 가기](#목차)

#### pop push shift unshift
  - 4개의 메소드를 통해 `Queue`, `Stack`, `Deque`를 만든다.
1. `push`: 맨 끝에 요소를 추가
2. `unshift`: 맨 앞에 요소를 추가
3. `shift`: 제일 앞 요소를 꺼내 제거하고 남은 요소들을 앞으로 밀어준다.
4. `pop`: 제일 끝 요소를 꺼낸다.

- `Queue`(FIFO): push shift
- `Stack`(LIFO): push pop
- `Deque`: push pop, unshift shift
```node
// 여러 개를 한 번에 더해줄 수도 있다. 
let fruits = ["사과"];

fruits.push("오렌지", "배");
fruits.unshift("파인애플", "레몬");

// ["파인애플", "레몬", "사과", "오렌지", "배"]
```


[😊목차 가기](#목차)

#### 반복문
1. 일반 for문
2. for of문
3. for in문: key가 숫자가 아닌 프로퍼티도 탐색(되도록 쓰지말 것)
``` node
let arr = ["사과", "오렌지", "배"];

//1. 일반 for문
for (let i = 0; i < arr.length; i++) {
  alert( arr[i] ); // 사과 오렌지 배
}

//2. for of문
for (let fruit of arr) {
  alert( fruit ); // 사과 오렌지 배
}

//3. for in문
for (let key in arr) {
  alert( arr[key] ); // 사과, 오렌지, 배
}
```

[😊목차 가기](#목차)

#### 다차원 배열
```node
let matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
];

alert( matrix[1][1] ); // 5, 중심에 있는 요소
```

[😊목차 가기](#목차)

#### toString

```node
let arr = [1, 2, 3];

alert( arr ); // 1,2,3
alert( String(arr) === '1,2,3' ); // true
```

[😊목차 가기](#목차)
