/*
  이동하면서 확인하면 끝
*/

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int w, h;
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		cin >> s;
		int ans = -1;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'c') {
				ans = 0;
			}

			if (ans != -1 && s[j] == '.') {
				ans++;
			}

			cout << ans << ' ';
		}
		cout << '\n';
	}

	return 0;
}
