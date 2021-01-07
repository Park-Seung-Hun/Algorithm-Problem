#include <iostream>
using namespace std;

int main() {
	
	int E, S, M;
	cin >> E >> S >> M;
	
	int e, s, m;
	e = s = m = 1;
	int ans = 1;
	
	while (true) {
		if (E == e && S == s && M == m) break;

		e++; s++; m++;
		ans++;

		if (e == 16) e = 1;
		if (s == 29) s = 1;
		if (m == 20) m = 1;
	}

	cout << ans << '\n';
}

/*
	백준 1476번 날짜 계산
*/
