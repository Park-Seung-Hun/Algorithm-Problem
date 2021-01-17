#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n = 0;
		int m = 0;
		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
		}
		cout << n - 1 << '\n';
	}

}
/*
	백준 9372번 상근이의 여행
*/
