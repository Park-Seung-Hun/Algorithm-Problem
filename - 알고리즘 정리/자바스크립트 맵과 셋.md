코딩 테스트 대비 JavaScript
================
# 목차
- [맵과 셋](#맵과-셋)
  - [맵](#맵)
  - [맵의 요소에 반복 작업](#맵의-요소에-반복-작업)
  - [객체를 맵으로](#객체를-맵으로): Object.entries 
  - [맵을 객체로](#맵을-객체로): Object.fromEntries
  - [셋](#셋)
  - [셋의 값에 반복 작업](#셋의-값에-반복-작업)

### 맵과 셋
#### 맵
  - 맵은 key가 있는 데이터를 저장한다는 점에서 객체와 유사하지만 `key`에 다양한 자료형을 허용한다는 점에서 차이
    - `new Map()`: 맵을 만든다
    - `map.set(ket,value)`: key를 이용해 value를 저장한다.
    - `map.get(key)`: key에 해당하는 값을 반환, 없으면 undefined
    - `map.has(key)`: key가 존재하면 true, 없으면 false
    - `map.delete(key)`: key에 해당하는 값을 삭제
    - `map.clear()`: 맵안의 모든 요소를 제거
    - `map.size`: 요소의 개수 반환

```node
// 일반적인 key 값
let map = new Map();

map.set('1', 'str1');   // 문자형 키
map.set(1, 'num1');     // 숫자형 키
map.set(true, 'bool1'); // 불린형 키

// 객체는 키를 문자형으로 변환
// 맵은 키의 타입을 변환시키지 않고 그대로 유지합니다. 따라서 아래의 코드는 출력되는 값이 다릅니다.
alert( map.get(1)   ); // 'num1'
alert( map.get('1') ); // 'str1'

// 객체를 key 값
let john = { name: "John" };


let visitsCountMap = new Map(); // 고객의 가게 방문 횟수를 세본다고 가정해 봅시다.

visitsCountMap.set(john, 123); // john을 맵의 키로 사용하겠습니다.

alert( visitsCountMap.get(john) ); // 123
// 원하는 값(123)을 얻으려면 아래와 같이 키가 들어갈 자리에 `object Object`를 써줘야합니다.
alert( visitsCountObj["[object Object]"] ); // 123
```

[😊목차 가기](#목차)

#### 맵의 요소에 반복 작업
  - `map.keys()`: 각 요소의 키를 모은 반복 가능한 객체를 반환
  - `map.values()`: 각 요소의 값을 모은 반복가능한 객체를 반환
  - `map.entries()`: 요소의 [key,value] 값을 한 쌍으로 하는 객체 반환 (for of 반복문의 기초)
 
 ```node
let recipeMap = new Map([
  ['cucumber', 500],
  ['tomatoes', 350],
  ['onion',    50]
]);

// 키(vegetable)를 대상으로 순회합니다.
for (let vegetable of recipeMap.keys()) {
  alert(vegetable); // cucumber, tomatoes, onion
}

// 값(amount)을 대상으로 순회합니다.
for (let amount of recipeMap.values()) {
  alert(amount); // 500, 350, 50
}

// [키, 값] 쌍을 대상으로 순회합니다.
for (let entry of recipeMap) { // recipeMap.entries()와 동일합니다.
  alert(entry); // cucumber,500 ...
} 
 ```

[😊목차 가기](#목차)

#### 객체를 맵으로
  - `Object.entries`: 각 요소가 key-value 쌍인 배열이나 반복 가능한 객체를 초기화 용도로 맵에 전달해 새로운 맵을 만들 수 있다.

```node
let obj = {
  name: "John",
  age: 30
};

let map = new Map(Object.entries(obj));

alert( map.get('name') ); // John
```

[😊목차 가기](#목차)

#### 맵을 객체로
  - `Object.fromEntries`: 각 요소가 [key, value]쌍인 배열을 객체로 바꿔준다.

```node
let prices = Object.fromEntries([
  ['banana', 1],
  ['orange', 2],
  ['meat', 4]
]);

// now prices = { banana: 1, orange: 2, meat: 4 }

alert(prices.orange); // 2
```

[😊목차 가기](#목차)

#### 셋
- 중복을 허용하지 않는 값을 모아놓은 컬렉션으로, `key가 없는 value가 저장`
  - `new Set(iterable)`: 셋을 만든다. 반복가능한 객체를 전달받으면(대게 배열) 그 안의 값을 복사해 set에 넣어준다.
  - `set.add(value)`: value를 추가하고 set 자신을 반환한다.
  - `set.delete(value)`: value 값을 제거한다.(제거 성공시 true, 실패시 false)
  - `set.has(value)`: set 내에 value가 존재하면 true, 아니면 false 반환
  - `set.clear()`: set을 비운다.
  - `set.size`: set에 몇 개의 value가 있는지 세준다.

```node
let set = new Set();

// set에 객체 저장
let john = { name: "John" };
let pete = { name: "Pete" };
let mary = { name: "Mary" };

// 어떤 고객(john, mary)은 여러 번 방문할 수 있습니다.
set.add(john);
set.add(pete);
set.add(mary);
set.add(john);
set.add(mary);

// 셋에는 유일무이한 값만 저장됩니다.
alert( set.size ); // 3

for (let user of set) {
  alert(user.name); // // John, Pete, Mary 순으로 출력됩니다.
}
```

[😊목차 가기](#목차)

#### 셋의 값에 반복 작업
- `for...of`나 `forEach`를 사용하면 set의 value를 대상으로 반복 작업 수행 가능.
  - `set.keys()`: set내의 모든 값을 포함하는 반복 가능한 객체를 반환.
  - `set.values()`: set.keys와 동일한 작업
  - `set.entries()`: 
```node
let set = new Set(["oranges", "apples", "bananas"]);

for (let value of set) alert(value);

// forEach를 사용해도 동일하게 동작합니다.
set.forEach((value, valueAgain, set) => {
  alert(value);
});
```

[😊목차 가기](#목차)

