코딩 테스트 대비 JavaScript
================
# 목차
- [문자열](#문자열)
  - [따옴표](#따옴표): 작은따옴표, 백틱
  - [문자열 프로퍼티](#문자열-프로퍼티): for of 반복문
  - [문자열 불변성](#문자열-불변성): 문자열은 수정 불가능
  - [대소문자 변경하기](#대소문자-변경하기): toUpperCase(), toLowerCase()
  - [부분 문자열 찾기](#부분-문자열-찾기): str.indexOf(substr,pos), str.lastIndexOf(substr,pos) => 위치 
  - [부분 문자열 추출하기](#부분-문자열-추출하기): `str.slice(start,end)`, str.substring(start,end), str.substr(start,length)
  - [문자열 비교하기](#문자열-비교하기)

### 문자열
#### 따옴표

```node
let single = '작은따옴표';
let double = "큰따옴표";

let backticks = `백틱`;
```

[😊목차 가기](#목차)

#### 문자열 프로퍼티
```node
let str="String"

str.length // 6 문자열 길이 반환
str[0] // 'S'
str.charAt(1) // 't'

for(let char of str){
   alert(char) // S t r i n g 차례로 출력
}
```

[😊목차 가기](#목차)

#### 문자열 불변성
   - 문자열은 수정 할 수 없다.
```node
let str = 'Hi';
str = 'h' + str[1]; // 문자열 전체를 교체함
// str[0] = 'T' 동작이 안됨
alert( str ); // hi
```

[😊목차 가기](#목차)

#### 대소문자 변경하기
```node
alert( 'Interface'.toUpperCase() ); // INTERFACE
alert( 'Interface'.toLowerCase() ); // interface
alert( 'Interface'[0].toLowerCase() ); // 'i'
```

[😊목차 가기](#목차)

#### 부분 문자열 찾기
- `str.indexOf` 이용
   - str.indexOf(substr,pos) : str의 pos에서부터 시작해 substr의 위치를 반환하고, 존재하지 않을 시 -1 반환
   - str.lastIndexOf(substr, position) : str의 뒷부분에서 부분 문자열을 찾는다.
```node
let str = "As sly as a fox, as strong as an ox";
let target = "as";

let pos = -1;
while ((pos = str.indexOf(target, pos + 1)) != -1) {
  alert( `위치: ${pos}` );
}
```

- `includes`, `startsWith`, `endsWith`
   - str.includes(substr,pos) : 부분 문자열 존재 여부에 따라 true or false
   - str.startsWith(substr), str.endsWith(substr) : str이 특정 문자열로 시작하는지 여부와 특정 문자열로 끝나는지 여부를 확인
```node
alert( "Widget".includes("id") ); // true
alert( "Widget".includes("id", 3) ); // false, 세 번째 위치 이후엔 "id"가 없습니다.

alert( "Widget".startsWith("Wid") ); // true, "Widget"은 "Wid"로 시작합니다.
alert( "Widget".endsWith("get") ); // true, "Widget"은 "get"으로 끝납니다.
```

[😊목차 가기](#목차)

#### 부분 문자열 추출하기
   - 부분 문자열 추출 메서드는 3가지이다.
   - `str.slice(start,end)`: start부터 end-1까지 문자열 반환 **가장 많이 사용**
   - `str.substring(start, end)`: start부터 end-1까지 문자열 반환 (start가 end보다 커도 괜찮다)
   - `str.subsrt(start, length)`: start부터 length만큼 문자열 반환
```node
let str = "stringify";

// 1.slice
alert( str.slice(0, 5) ); // 'strin', 0번째부터 5번째 위치까지(5번째 위치의 글자는 포함하지 않음)
alert( str.slice(2) ); // ringify, 2번째부터 끝까지
alert( str.slice(-4, -1) ); // gif

// 2. substring
// 동일한 부분 문자열을 반환합니다.
alert( str.substring(2, 6) ); // "ring"
alert( str.substring(6, 2) ); // "ring"

// 3. substr
alert( str.substr(2, 4) ); // ring, 두 번째부터 글자 네 개
alert( str.substr(-4, 2) ); // gi, 끝에서 네 번째 위치부터 글자 두 개
```

[😊목차 가기](#목차)

#### 문자열 비교하기
  - str.codePointAt(pos): pos에 위치한 글자의 유니코드를 반환한다.
  - str.fromCodePoint(code): 숫자 형식의 code에 대응하는 글자를 만든다.
  - str.localeCompare(str2): str<str2 음수, str>str2 양수, str===str2 0

```node
// 1. str.codePointAt(pos)
alert( "z".codePointAt(0) ); // 122
alert( "Z".codePointAt(0) ); // 90

// 2. str.fromCodePoint(code)
alert( String.fromCodePoint(90) ); // Z

// 3. str.localeCompare(str2)
alert( 'Österreich'.localeCompare('Zealand') ); // -1
```

[😊목차 가기](#목차)
