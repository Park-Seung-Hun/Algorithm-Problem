# JavaScript 코딩 테스트 준비

- [JS Event Loop](https://asfirstalways.tistory.com/362)
- [JS 비동기 처리과정](http://sculove.github.io/blog/2018/01/18/javascriptflow/)
- [JS Promise Async/Await](https://velog.io/@yejinh/%EB%B9%84%EB%8F%99%EA%B8%B0-%ED%8C%8C%ED%97%A4%EC%B9%98%EA%B8%B0)

## 목차
  - [문자열](#문자열)
  - [배열](#배열)
  - [객체](#Object)
  - [Map](#Map)
  - [Set](#Set)
  - [우선순위큐](#우선순위-큐)
  - [순열과 조합](#순열과-조합)
  - [소수 찾기](#소수-찾기)
  - [BFS](#BFS)
  - [DFS](#DFS)
  - [다익스트라](#다익스트라)
  - [플로이드 와샬](#플로이드-와샬)
  - [이진트리](#이진트리)
  - [GCD LCM](#GCD-LCM)


#### `includes()` `indexOf()` - 문자열 & 배열
=> 배열 및 문자열에서 사용 가능하다.

```js
let arr = [1,2,3,4,5]
let str = "abcde"

console.log(arr.includes(1)); // true
console.log(arr.indexOf(3)); // 2

console.log(str.includes('a')); // true
console.log(str.indexOf('c')); // 2
```

## 문자열
### 요약
- `str.split('')` : 문자열을 나눠 배열로 만든다.
- `parseInt(str,진법)` : 해당 진법으로 표현된 문자열을 10진법으로 만든다.
- `num.toString(진법)` : 10진법 숫자를 해당 진법의 문자열로 변환
- `str.substr(시작 idx, 길이)` : 시작 인덱스에서 길이만큼 반환
- `str.slice(시작 idx, 종료 idx)` : 시작 idx에서 종료 idx까지의 문자열 반환
- `str.split(/[^0-9]/).filter((a)=> a!=='')` : 문자열에서 숫자 추출
- `str.split(/[0-9]/).filter((a)=> a!=='')` : 문자열에서 문자만 추출
- `str.toLowerCase()` `str.toUpperCase()` : 소문자, 대문자
- `str.charCodeAt(idx)` : 해당 idx의 아스키 코드
- `String.fromCharCode(아스키 코드)` : 아스키 코드를 문자로 변환
- `문자열 추가` : 문자열+문자열, str.concat(문자열);
- `str.length` : 문자열의 길이 반환

[더 보러 가기](https://lktprogrammer.tistory.com/124)

[위로 가기](#목차)

## 배열
### 요약

- `배열 초기화` : Array.from(), new Array(길이).fill(초기값)
- `Array.isArray(arr)` : 배열인지 확인
- `Math.max.apply(null,arr)` : 배열의 최대 값 (길이가 10^7 이상인 경우 reduce() 사용)
- `Math.min.apply(null,arr)` : 배열의 최소 값 (길이가 10^7 이상인 경우 reduce() 사용)
- `배열의 합계, 평균`

```js
const sum = arr.reduce(function add(sum, currValue) {
      return sum + currValue;
}, 0);

const average = sum / arr.length;
```

- `arr.join('')` : 배열의 각 요소를 ''로 합쳐 문자열로 반환
- `arr.map(함수)` : 배열의 각 원소별로 지정된 함수를 실행한 결과로 구성된 새로운 배열을 반환한다. => 조건에 맞는 boolean 반환
- `arr.filter(함수)` : 지정된 함수의 결과 값을 true로 만드는 원소들로만 구성된 별도의 배열을 반환한다. => 배열의 원소 반환
- `arr.forEach(function (value){})` : 배열의 각 요소별로 지정된 함수를 실행한다.
- `arr.pop()` `arr.push()` : 배열 뒤에 요소를 삭제 후 반환 / 삽입
- `arr.shift()` `arr.unshift()`: 배열 앞에 요소를 삭제 후 반환/ 삽입
- `arr.splice(시작 idx, 길이, 추가할 요소)` : 시작 idx 부터 길이만큼 삭제 => 추가도 가능 (배열 자체가 변환)
- `arr.slice(시작 idx, 종료 idx)` : 시작 idx부터 종료 idx까지 새로운 배열 반환 (배열 변화 x)
- `arr.concat(arr1)` : 배열을 병합하여 반환
- `arr.reverse()` : 배열 뒤집기
- `arr.sort()` : 배열의 원소를 알파벳순으로, 또는 지정된 함수에 따른 순서로 정렬한다. (모든 원소를 문자열로 취급해 사전적으로 정렬)

[더 보러 가기](http://blog.302chanwoo.com/2017/08/javascript-array-method/)

[위로 가기](#목차)

## Object
=> Object의 key는 문자열, value는 모든 값이다.
### 요약
- `객체 선언 및 프로퍼티 할당`

```js
let O;
/* 객체 선언 */
O = new Object();
O = {};

/* 프로퍼티 할당 */
O[key]=value;
O.key=value;
```

- `Object.keys(객체명)` : 객체의 key를 배열로 반환한다.
- `Object.values(객체명)` : 객체의 value를 배열로 반환한다.
- `Object.entries(객체명)` : [key,value] 형식의 배열로 반환한다.
- `for(let key in Obj)` : 객체의 각각의 키를 반환한다.
- `key in 객체` : 객체에 key가 존재하면 true, 아니면 false

[더 보러 가기](https://ljtaek2.tistory.com/89)

[위로 가기](#목차)

## Map
=> Map의 key와 value는 모든 유형이 가능하다. (중복은 안됨, key가 정렬)
=> Map은 Object와 달리 has가 아주 좋다.

### 요약
- `new Map()` : 새로운 맵을 생성
- `map.set(key,value)` : value를 key로 저장
- `map.get(key)` : key가 존재하면 value, 존재하지 않으면 undefined
- `map.has(key)` : key가 존재하면 true, 아니면 false
- `map.delete(key)` : key를 제거
- `map.clear()` : 맵의 모든 것을 제거
- `map.size` : 현재 요소의 개수를 리턴
- `map.keys().next().value` : map의 key 중 가장 처음 값 (한번 더 출력시 그 다음 값)
- `map.values().next().value` : map의 value 중 가장 처음 값 (한번 더 출력시 그 다음 값)
- `map.entries().next().value` : map의 entry 중 가장 처음 값 (한번 더 출력시 그 다음 값)
- `for..of, forEach로 Map 순회하기`

```js
let myMap = new Map()
myMap.set(0, 'zero')
myMap.set(1, 'one')

for (let [key, value] of myMap) {
  console.log(key + ' = ' + value)
}
// 0 = zero
// 1 = one

for (let key of myMap.keys()) {
  console.log(key)
}
// 0
// 1

for (let value of myMap.values()) {
  console.log(value)
}
// zero
// one

for (let [key, value] of myMap.entries()) {
  console.log(key + ' = ' + value)
}
// 0 = zero
// 1 = one

myMap.forEach(function(value, key) {
  console.log(key + ' = ' + value)
})
// 0 = zero
// 1 = one
```

- `배열과 Map의 관계`

```js
let kvArray = [['key1', 'value1'], ['key2', 'value2']]

// Use the regular Map constructor to transform a 2D key-value Array into a map
let myMap = new Map(kvArray)

myMap.get('key1') // returns "value1"

// Use Array.from() to transform a map into a 2D key-value Array
console.log(Array.from(myMap)) // Will show you exactly the same Array as kvArray

// A succinct way to do the same, using the spread syntax
console.log([...myMap])

// Or use the keys() or values() iterators, and convert them to an array
console.log(Array.from(myMap.keys())) // ["key1", "key2"]
```

[더 보러 가기](https://oneroomtable.tistory.com/entry/%EC%9E%90%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8-%EB%A7%B5-Map-%EC%A0%95%EB%A6%AC-%EC%A4%91#0h)

[위로 가기](#목차)

## Set
=> 자료형에 관계 없이 모두 저장 가능 (중복 x)
### 요약

- `Set 선언 및 할당`

```js
let mySet = new Set();
mySet.add(1);
mySet.add(5);
mySet.add(5); // Set {1, 5}
```

- `set.has(value)` : value가 존재하면 true, 아니면 false
- `set.size` : set의 길이
- `set.delete(value)` : value 제거
- `Set 반복 및 배열과 관계`

```js
// set 내 항목에 대해 반복
// 순서대로 항목을 (콘솔에) 기록: 1, "some text", {"a": 1, "b": 2}
for (let item of mySet) console.log(item);

// 순서대로 항목을 기록: 1, "some text", {"a": 1, "b": 2}
for (let item of mySet.keys()) console.log(item);

// 순서대로 항목을 기록: 1, "some text", {"a": 1, "b": 2}
for (let item of mySet.values()) console.log(item);

// 순서대로 항목을 기록: 1, "some text", {"a": 1, "b": 2}
// (여기서 key와 value는 같음)
for (let [key, value] of mySet.entries()) console.log(key);

// Set 객체를 배열 객체로 변환 (Array.from으로)
var myArr = Array.from(mySet); // [1, "some text", {"a": 1, "b": 2}]
```

[더 보러 가기](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Set)

[위로 가기](#목차)


### 우선순위 큐
```js
let item;
priority_queue.push(item);
priority_queue.sort(function (a,b){
    // return a-b; : 최소 힙
    // return b-a; : 최대 힙
});
```

[위로 가기](#목차)


### 순열과 조합
- 조합
  - 순서가 바뀌어도 하나의 조합으로 생각한다.

```js
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

```js
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

[위로 가기](#목차)


### 소수 찾기
  - 에라토스테네스의 체를 이용한 소수 찾기

```js
let check=Array.from({length: prime[prime.length-1]+1}, ()=>false); // 소수 체크 배열

check[0]=check[1]=true;
let maxNum==prime[prime.length-1];
for(let i=2;i<maxNum;i++){
    if(check[i]===false){
        for(let j=i+i;j<=maxNum;j+=i) check[j]=true;
    }
}
for(let num of prime) {
    if(check[num]===false) answer++;
}
```

[위로 가기](#목차)

### BFS

```js
//  BFS 정의
let visited = Array.from({length:n},()=>false); // 방문 배열
    const bfs = function(cur){
        let queue = [];
        queue.push(cur);

        while(queue.length!==0){
            let here = queue.shift();

            for(let i=0;i<edge[here].length;i++){
                let there = edge[here][i];
                if(visited[there]) continue;
                visited[there]=true;
                queue.push(there);
            }
        }
    }
```

[위로 가기](#목차)


### DFS

```js
let check = Array.from({length: n},()=>false);
const dfs = function(str,tg,cnt){
    if(str===tg){
        if(cnt<answer) answer=cnt;
        return;
    }

    for(let i=0;i<words.length;i++){
        if(checkStr(str,words[i])&&check[i]===false){
            check[i]=true;
            dfs(words[i],tg,cnt+1);
            check[i]=false;
        }
    }
}
```

[위로 가기](#목차)

### 다익스트라

```js
    /* 최소 거리 정보를 저장하는 Dist */
    let Dist = new Array(N+1).fill(987654321);

    /* 연결된 거리 정보를 저장하는 vertex와 초기화*/
    let vertex = new Array(N+1).fill(null).map(()=>new Array());
    for(i=0;i<road.length;i++){
        arr=road[i];
        console.log(arr);
        vertex[arr[0]].push([arr[1], arr[2]]);
        vertex[arr[1]].push([arr[0], arr[2]]);
    }


    /* 우선순위 큐를 이용한 Dijkstra */
    const Dijkstra = function (start){
        let pq = [];
        pq.push([start,0]);
        Dist[start]=0;

        while(pq.length !== 0){
            arr = pq.shift();
            let cost = arr[1];
            let cur = arr[0];

            for(i=0;i<vertex[cur].length;i++){
                arr = vertex[cur][i];
                let ncost = arr[1];
                let next = arr[0];

                if(Dist[next]>cost+ncost){
                    Dist[next]=cost+ncost;

                    pq.push([next,Dist[next]]);
                    pq.sort(function(a,b){
                        if(a[1]<b[1]) return -1;
                        if(a[1]===b[1]) return 0;
                        if(a[1]>b[1]) return 1;
                    })
                }
            }
        }
    }

    Dijkstra(1);
```

[위로 가기](#목차)

### 플로이드 와샬

```js
// 노드 사이의 거리를 위한 vertex배열 생성.
let vertex = new Array(n+1).fill(null).map(()=>new Array(n+1).fill(987654321));

// 거리 초기화.
for(i=0;i<fares.length;i++){
    arr=fares[i];
    vertex[arr[0]][arr[1]] = arr[2];
    vertex[arr[1]][arr[0]] = arr[2];
}
for(i=0;i<=n;i++) vertex[i][i]=0; // 자기 자신한테는 0

// 플로이드 와샬 알고리즘
const floyd_warwhall = function(){
    for(let k=1;k<=n;k++){
        for(let i=1;i<=n;i++){
            for(let j=1;j<=n;j++){
                if(vertex[i][k]===987654321||vertex[k][j]===987654321) continue;

                if(vertex[i][j]>vertex[i][k]+vertex[k][j]) vertex[i][j]=vertex[i][k]+vertex[k][j];
            }
        }
    }

}
floyd_warwhall();
```


[위로 가기](#목차)

### 이진트리
=> x,y 값을 이용한 이진트리 만들기

```js
function solution(nodeinfo) {
    let rootNode
    let preorder = []
    let postorder = []

    /* 노드 값 초기화 */
    const Node = function (x, y, id) {
        this.x = x // 위치
        this.y = y // 높이
        this.id = id
        this.left = null
        this.right = null
    }

    const _insertNode = (node, x, y, id) => {
        const side = x < node.x ? 'left' : 'right'

        if (node[side] === null) {
            /*
                자식 노드가 존재하지 않는 경우 => 노드 생성 (node.x값보다 작은 경우 left , node.x보다 큰 경우 right)
            */
            node[side] = new Node(x, y, id)
        } else {
            /*
                자식 노드가 존재하는 경우 => 자식노드에서 반복
            */
            _insertNode(node[side], x, y, id)
        }
    }

    /* 노드 입력 */
    const insertNode = (x, y, id) => {

        if (!rootNode) { // root노드가 없는 경우 => root노드 생성
            rootNode = new Node(x, y, id)
        } else { // root노드가 있는 경우 => root노드부터 시작해 노드 삽입
            _insertNode(rootNode, x, y, id)
        }
    }

    /* 전위 순회 root -> 좌 -> 우*/
    const _preorder = node => {
        preorder.push(node.id)
        if (node.left) _preorder(node.left)
        if (node.right) _preorder(node.right)
    }

    /* 후위 순회 좌 -> 우 -> root */
    const _postorder = node => {
        if (node.left) _postorder(node.left)
        if (node.right) _postorder(node.right)
        postorder.push(node.id)
    }

    /* 노드 값 정리 [x,y,idx] 후 y 값에 대해 내림차순 정렬 */
    const nodes = nodeinfo.map(([x, y], idx) => [x, y, idx+1]);
    nodes.sort(([, ya], [, yb]) => yb - ya)

    /* 정리된 노드 값을 이진 트리로 만들기 */
    nodes.forEach(([x, y, id]) => insertNode(x, y, id))

    _preorder(rootNode)
    _postorder(rootNode)

    return [preorder, postorder]
}
```

### GCD LCM

```js
// 최대 공약수
const gcd = function(a,b){
    if(b===0) return a;
    else return gcd(b,a%b);
}

// 최소 공배수
const lcm = function(a,b){
    let g=gcd(a,b);
    return g*parseInt(a/g)*parseInt(b/g);
}
```

[위로 가기](#목차)
