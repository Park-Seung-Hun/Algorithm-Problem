코딩 테스트 대비 JavaScript
================
# 목차
- [숫자형](#숫자형)
  - [숫자의 다양한 표현](#숫자의-다양한-표현): 간단한 수학식, 진수표현, 숫자
  - [isNaN과 isFinite](#isNaN과-isFinite): value를 숫자로 변환한 다음 
  - [parseInt와 parseFloat](#parseInt와-parseFloat): 문자열을 불가능할 때까지 숫자로 변경한다.
  - [기타 수학 함수](#기타-수학-함수): 최대 최소, 


### 숫자형
#### 숫자의 다양한 표현
```node
let billion = 1000000000;
let billion = 1e9;  // 10억, 1과 9개의 0

let ms = 0.000001;
let ms = 1e-6; // 1에서 왼쪽으로 6번 소수점 이동

let Num;
Num = 0xff // 255 16진수
Num = 0b11111111; // 255의 2진수
Num = 0o377; // 255의 8진수

let num = 255; // nom.toString(base)

alert( num.toString(16) );  // ff
alert( num.toString(2) );   // 11111111

Math.floor(3.6) // 3 버림
Math.ceil(3.1) // 4 올림
Math.round(3.1) // 3 
Math.round(3.6) // 4 반올림
Math.trunc(3.1) // 3 소수부 무시

let sum=0.1+0.2; // 부정확한 계산
sum.toFixed(2) // "0.30" 문자열 반환.
+sum.toFixed(2) // 0.3 숫자 반환
```

[😊목차 가기](#목차)

#### isNaN과 isFinite

- inNaN(value): value를 숫자로 변환한 다음 NaN인지 테스트
```node
alert( isNaN(NaN) ); // true
alert( isNaN("str") ); // true
```
- isFinite(value): value를 숫자로 변환한 숫자가 일반 숫자인경우 true반환
```node
alert( isFinite("15") ); // true
alert( isFinite("str") ); // false, NaN이기 때문입니다.
alert( isFinite(Infinity) ); // false, Infinity이기 때문입니다.
```


[😊목차 가기](#목차)

#### parseInt와 parseFloat
   - 불가능할 때까지 문자열에서 숫자를 읽어 반환한다
```node
alert( parseInt('100px') ); // 100
alert( parseFloat('12.5em') ); // 12.5

alert( parseInt('12.3') ); // 12, 정수 부분만 반환됩니다.
alert( parseFloat('12.3.4') ); // 12.3, 두 번째 점에서 숫자 읽기를 멈춥니다.

lert( parseInt('a123') ); // NaN, a는 숫자가 아니므로 숫자를 읽는 게 중지됩니다.

alert( parseInt('0xff', 16) ); // 255
alert( parseInt('ff', 16) ); // 255, 0x가 없어도 동작합니다.
alert( parseInt('2n9c', 36) ); // 123456
```

[😊목차 가기](#목차)

#### 기타 수학 함수

```node
Math.random() // 랜덤 수 반환 0~1사이
Math.max(a,b,c,....) // 최대
Math.min(a,b,c,....) // 최소
Math.pow(n.power) // n을 power번 거듭제곱
```

[😊목차 가기](#목차)


