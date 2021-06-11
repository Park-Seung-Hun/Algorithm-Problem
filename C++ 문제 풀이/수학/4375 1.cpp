#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;

	while (cin >> n) {
		int num=0;
		for (int i = 1; i <= n; i++) {
			num = 10 * num + 1;
			num %= n;

			if (num == 0) {
				cout << i << '\n';
				break;
			}
		}

	}
	return 0;
}
