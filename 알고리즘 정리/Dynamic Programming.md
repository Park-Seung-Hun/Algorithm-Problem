Dynamic Programming(다이나믹 프로그래밍)
===========

- 다이나믹 프로그래밍 이란?
> 복잡한 문제를 간단한 여러개의 문제로 나누어 푸는 방법 

한 가지 문제에 대해서, 단 한 번만 풀도록 만들어주는 알고리즘이다. 즉, 똑같은 연산을 반복하지 않도록 만들어준다.<br>
실행 시간을 줄이기 위해 많이 이용되는 **수학적 접근 방식의 알고리즘**이라고 할 수 있다.<br><br>

- 접근 방식<br>

커다란 문제를 쉽게 해결하기 위해 작게 쪼개서 해결하는 방법인 분할 정복과 매우 유사하다<br>
하지만 간단한 문제로 만드는 과정에서 중복 여부에 대한 차이점이 존재한다.<br>
다이나믹 프로그래밍은 간단한 작은 문제들 속에서 **계속 반복되는 연산(점화식)**을 활용하여 빠르게 풀수 있는 것이 핵심이다.<br><br>

- 조건<br>
> 두가지 조건을 만족하면 다이나믹 프로그래밍을 이용해 문제 해결이 가능하다.

1. 작은 문제에서 반복이 일어남
2. 같은 문제는 항상 정답이 같음
<br><br>
 
- 구현 방식<br>
1. **Bottom-up**: 작은 부분문제들을 미리 계산하고, 계산한 문제들을 모아 큰 문제를 해결하는 방식.
> 반복문을 통해 구현. 
>>시간 및 메모리의 최적화가 쉽지만, 큰 문제를 해결하기까지 어떠한 부분문제들이 요구되는지 알 수 없으므로 전체 문제를 계산하기 위해 모든 부분문제를 해결해야 한다.<br>

2. **Top-down**: 큰 문제에서 작은 부분문제를 재귀적으로 호출하여 리턴되는 값을 이용해 해결하는 방식.
> 재귀함수를 통해 구현. 
>>호출에 대한 오버헤드가 발생하지만, 큰 문제를 해결하기 위해 필요한 부분문제만 호출하므로 빠르게 동작 가능.<br>


<h4>**메모이제이션(memoization) 기법</h4>
중복되는 부분문제를 피하기 위해 사용되는 기법으로, 계산된 문제를 저장하는 자료구조를 선언한다.<br>
재귀호출이나 다이나믹 프로그래밍에서 시간복잡도를 줄여주는 기법.

### 피보나치 수열 코드
```c++
#include <iostream>
using namespace std;

int num;
int memo_r[1001];
int memo_m[1001] = { 0,1, };
int last_pos = 1;

int top_down_r(int n) {
	if (n <= 0) return 0;
	if (n <= 1) return 1;
	else return top_down_r(n - 1) + top_down_r(n - 2);
}//top-down 재귀

int top_down_m(int n) {
	if (n <= 1) return n; //0번째, 1번째 피보나치 수
	if (memo_r[n] != 0) return memo_r[n]; //이전에 계산된 부분문제일 경우 반환
	memo_r[n] = top_down_m(n - 1) + top_down_m(n - 2);
	return memo_r[n];
}// top-down 메모이제이션

int bottom_up_m(int n) {
	int i;
	if (memo_m[n] == 0) { // 계산한 적이 없는 경우 구한다.
		for (i = last_pos + 1; i <= n; ++i) {
			memo_m[i] = memo_m[i - 1] + memo_m[i - 2];
		}
		last_pos = n;
	}
	return memo_m[n];
} // bottom-up 메모이제이션

int main() {
	cin >> num;
	cout << top_down_r(num) << '\n';
	cout << top_down_m(num) << '\n';
	cout << bottom_up_m(num) << '\n';
}


/*
 input:
 10
 
 output:
 55
 55
 55
*/
```
참고 사이트 : [코드그라운드 노트](https://www.codeground.org/common/popCodegroundNote), [Rise 마법의 슈퍼마리오 블로그](https://m.blog.naver.com/kks227/220796963742)
