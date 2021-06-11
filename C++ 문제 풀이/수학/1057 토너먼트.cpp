#include <iostream>
using namespace std;
int n, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> a >> b;
	int ans = 0;
	while (true) {
		if (a % 2 == 1) a++;
		if (b % 2 == 1) b++;

		a /= 2;
		b /= 2;
		ans++;
		if (a == b)break;
	}

	cout << ans << '\n';
	return 0;
}
