#include <iostream>
using namespace std;

int GCD(int a, int b) {
	if (a % b == 0) return b;
	return GCD(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;

	int x, y;
	x = a * d + c * b;
	y = b * d;

	cout << x / GCD(x, y) << ' ' << y / GCD(x, y) << '\n';
}



/*
	백준 1735번 분수 합
*/
