#include <iostream>
#include <map>
using namespace std;
int t, n;
int num[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int ans = 1;
		string a, b;
		map<string, int> m;
		for (int j = 0; j < n; j++) {
			cin >> a >> b;

			if (m.find(b) == m.end()) m[b] = 1;
			else m[b]++;
		}

		for (auto j : m) {
			ans *= (j.second + 1);
		}
		cout << ans-1 << '\n';
	}
	return 0;
}
