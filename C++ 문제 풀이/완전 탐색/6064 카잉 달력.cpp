#include <iostream>
using namespace std;

int test;
int n, m, x, y;

int GCD(int a, int b) {
	if (a % b == 0) return b;
	return GCD(b, a % b);
}

int LCM(int a, int b) {
	return (a * b) / GCD(a, b);

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> m >> n >> x >> y;
		int maxYear = LCM(m, n);

		while (true) {
			if (x > maxYear || (x - 1) % n + 1 == y)break;

			x += m;
		}
		if (x > maxYear) cout << -1 << '\n';
		else cout << x << '\n';
	}
}
/*
	백준 6064번 카잉 달력
*/
