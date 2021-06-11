# JAVA 코딩 테스트 준비

## 목차
  - [Array](#Array)
  - [Stack](#Stack)

### Array
> Arrays는 선언 전 `import java.util.Arrays;`를 먼저 선언한다.<br>
> [배열 정렬 자세히 보기](https://coding-factory.tistory.com/549)


  - `배열 선언 및 초기화`

```JAVA
int[] array = new int[4];  
int[][] array = new int[2][5]; // 선언만
int[][] array = new int[3][]; // 가변 크기 배열 선언

int[] array = {1,2,3,4,5,6,7};
int[][] array = {{1,2,3,4},{5,6,7,8}} // 선언과 초기화
```

  - `Array.length` : 배열의 길이
  - `for(int value:array){}` : for each 구문으로 value 값을 참조.
  - `Arrays.sort(배열)` : 배열을 오름차순으로 정렬
  - `Arrays.sort(배열,Collections.reverseOrder())` : 배열을 내림차순으로 정렬
     - 배열의 정렬은 객체 배열도 정렬가능.
  - `Arrays.toString(배열)` : 배열을 문자열로 변환
  - `Arrays.binarySearch(배열,value)` : 배열에 value가 존재하면 위치를 반환한다.
  - `int[] arr2 = Arrays.copyOf(배열,길이)` : 배열 복사
  - `int[] arr2 = Arrays.copyOfRange(배열,시작 위치,마지막 위치)` : 시작 위치부터 마지막 위치 까지 복사 (길이를 벗어나는 위치를 선정하면 0으로 채워진다.)
  - `Arrays.equals(arrA, arrB)` : 두 배열이 같으면 true, 아니면 false
  - `Arrays.fill(배열, value)` : 배열의 전체 원소를 value로 채운다.

[위로 가기](#목차)

### Stack
> Stack은 선언 전 `import java.util.Stack;`를 먼저 선언한다.

  - `Stack<자료형> stack = new Stack<>();`
    - 자료형 : Integer, String 등
  - `stack.push(value)` : stack에 값을 집어넣는다.
  - `stack.pop()` : stack의 가장 꼭대기 값을 제거한다.
  - `stack.clear()` : stack을 초기화 한다.
  - `stack.peek()` : stack의 가장 상단 값 출력
  - `stack.size()` : stack의 크기 출력
  - `stack.empty()` : stack이 비어 있을 경우 true
  - `stack.contains(value)` : stack에 value가 존재할 경우 true

[위로 가기](#목차)
