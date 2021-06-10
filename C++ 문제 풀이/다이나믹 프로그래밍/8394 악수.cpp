/*
8394 악수
sol. DP로 푼다.
1. 메모리초과로 인해 dp배열을 만들지 않고 풀이 (a,b)
2. 범위 초과로 1의 자리만 출력
*/

#include <iostream>
#include <vector>
using namespace std;
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int a = 1, b = 1;

	for (int i = 2; i <= N; i++) {
		int tmp = b;
		b = (a + b) % 10;
		a = tmp % 10;
	}

	cout << b;
	return 0;
}
