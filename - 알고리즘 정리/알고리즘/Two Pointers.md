Two Pointers(투 포인터)
===========

- 투 포인터란?
> 1차원 배열에서 **각자 다른 원소를 가리키고 있는 2개의 포인터를 조작해 가며 원하는 것을 얻는 알고리즘**.

<br>

- 투 포인터의 동작1 <br>
  - `정렬된 두 배열 A,B가 주어졌을 때, 두 배열을 정렬된 하나의 배열 C로 합치는 경우.`<br>
> 배열 A={1,2,8,9} , 배열 B={-3,3,4,5,11} 을 하나의 배열C 로 합치는 예시.

1. A[i]와 B[j]중 작은 값을 찾아 넣는다. (i=0,j=0)
2. 작은 값이 B[0]이므로 j의 값을 1 증가 시킨다. (포인터 이동 i=0,j=1, C={-3}) 
3. 다시 A[i]와 B[j]중 작은 값을 찾아 넣고 작은 값이 포함된 배열의 포인터를 1 증가 시킨다.
4. 3번을 반복하다 보면 포인터가 배열의 크기를 넘어가게 되는데, 이때 해당 배열을 제외한 나머지 배열에서 포인터를 이동시키며 값을 넣는다.
<br>

##### 1번 Code
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A, B, C;
int a, b;

int main() {
	cin >> a;
	A.resize(a);
	for (int i = 0; i < a; i++) cin >> A[i];

	cin >> b;
	B.resize(b);
	for (int i = 0; i < b; i++) cin >> B[i];

	int idxa = 0, idxb = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());


	for (int i = 0; i < a + b; i++) {
		if (idxb == b || (idxb != b && idxa < a && A[idxa] < B[idxb])) C.push_back(A[idxa++]);
		else C.push_back(B[idxb++]);
	}

	for (int i = 0; i < a + b; i++) cout << C[i] << ' ';
}
/*
input:
4 배열 A 
1 2 8 9 A의 원소
5 배열 B
-3 3 4 5 11 B의 원소

output:
-3 1 2 3 4 5 8 9 11 C의 원소
*/

```

- 투 포인터의 동작2 <br>
 - `어떤 자연수만 있는 배열의 부분 연속합이 k인 경우의 수를 찾는 경우.`<br>
 > SUM[L,R]: 배열의 L부터 R-1까지의 합 
 
1. SUM[L, R] < k 일 때, R을 증가시켜주어 k에 근접할 수 있도록 범위를 넓혀준다.
2. SUM[L, R] > k 일 때, L을 증가시켜주어 범위를 좁혀준다.
3. SUM[L, R] == k 일 때는 정답을 카운트해주며 다음 경우를 찾기 위해 다시 L을 증가시켜주어 범위를 좁혀준다.

##### 2번 Code

```c++
#include <iostream>
using namespace std;

int n, m, tot;
int num[10000];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> num[i];

	int L = 0;
	int R = 0;
	int sum = 0;

	while (true) {
		if (sum >= m) sum -= num[L++];
		else if (R == n) break;
		else sum += num[R++];

		if (sum == m) tot++;
	}
	cout << tot;
}

/*
input:
10 5 원소의 개수, k
1 2 3 4 2 5 3 1 1 2 배열의 원소

output:
3 부분 연속합의 값이 k인 경우의 수
*/
```
참고 사이트 : [코드그라운드 노트](https://www.codeground.org/common/popCodegroundNote), [Rise 마법의 슈퍼마리오 블로그](https://m.blog.naver.com/kks227/220796963742)
