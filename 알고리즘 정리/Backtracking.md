Backtracking(백트래킹)
===========

- 백트래킹 이란?
> 어떤 노드의 유망성 점검후, **유망하지 않으면 그 노드의 부모노드로 되돌아간 후 다른 자손 노드를 검색**하는 알고리즘

백트래킹 문제는 **조합 알고리즘 문제에 대해 조건이 만족하는 가능한 모든 해를 나열하는 것**. 즉, 여기서 말하는 조건이 만족하는 가능한 모든 해는
유망성이 검증된 해이다.
<br>

- 백트래킹의 동작

> 백트래킹은 DFS에 조건을 설정하여 동작시킨다. 즉 스택 or 재귀함수를 통해 구현이 가능하다.
> 특히 주의할 점은 노드에서 DFS를 동작 한 후 DFS 하기 이전의 상태로 되돌려 놔야 한다는 점.
<br>

- 백트래킹 대표 문제<br>
[N 과 M 시리즈](https://www.acmicpc.net/problemset?search=N%EA%B3%BC+M)<br>
[N-Queen](https://www.acmicpc.net/problem/9663)<br>
[스도쿠](https://www.acmicpc.net/problem/2580)<br>

##### N과 M(1) Code
> 

```c++
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> num;
vector<bool> check;

void back(int cnt) {
	
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << num[i] << ' ';
		cout << '\n';
		return;
	} // 조건을 만족할 때 결과 값을 출력

	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			check[i] = true;
			num.push_back(i);
			back(cnt + 1);
			num.pop_back();
			check[i] = false; // 이전 상태로 되돌린다.
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	check.resize(n + 1);
	back(0);

}

/*
input:
4 2

output:
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
*/
```
참고 사이트 : [코드그라운드 노트](https://www.codeground.org/common/popCodegroundNote), [Rise 마법의 슈퍼마리오 블로그](https://m.blog.naver.com/kks227/220796963742)
