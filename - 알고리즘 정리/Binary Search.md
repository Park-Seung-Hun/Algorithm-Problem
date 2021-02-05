Binary Search(이진 탐색)
===========

- 이진 탐색 이란?
> 분할 정복의 한 예로, **오름차순으로 정렬된 배열에서 원하는 값을 시간복잡도 O(logN)만에 찾아내는 탐색법**

<br>

- 이진 탐색의 동작<br>

<img src="https://blog.kakaocdn.net/dn/bpv9gL/btqEChu74lV/Fuil3yXTuDmv2us2tPOoT1/img.gif" width="50%"><br>
>  탐색할 데이터의 범위를 `[L,R]` (L=0, R=N-1)로 설정. 사이즈가 N인 배열 D에서 K 찾기 
1. 중앙 값 `M=(L+R)/2`으로 설정한다.
2. `D[M]의 값< K`이면 `L=R+1`, `D[M]의 값> K`이면 `R=M-1`로 치환 후 1번을 반복한다.
3. 위와 같은 과정을 K를 찾을 때 까지 반복한다. 만일 찾으려는 값이 없으면 L>R이 되어 종료한다. (최대한 가까운 값을 찾음)
<br>

##### Code

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k;
int L, R, M;
vector<int> D;

bool Binary_Search(int K) {
	L = 0; R = n - 1;

	while (L <= R) {
		M = (L + R) / 2;

		if (D[M] < K) L = M + 1;
		else if (D[M] > K) R = M - 1;
		else return true;
	}

	return false;
}

int main() {
	cin >> n;
	D.resize(n);

	for (int i = 0; i < n; i++) cin >> D[i];
	sort(D.begin(), D.end());

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> k;
		if (Binary_Search(k)) cout << "exist\n";
		else cout << "not exits\n";
	}
	
}

/*
input:
8 원소의 수
-3 0 1 4 7 9 11 16 배열 D의 원소
5 명령 수
15 찾으려는 값 k
0
-3
14
100

output:
not exist
exist
exist
not exist
not exist
*/
```
참고 사이트 : [코드그라운드 노트](https://www.codeground.org/common/popCodegroundNote), [Rise 마법의 슈퍼마리오 블로그](https://m.blog.naver.com/kks227/220796963742)
