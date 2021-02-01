#include <iostream>
#include <string>
using namespace std;

int n, m;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> s;
	int ans = 0;

	for (int i = 0; i < m ; i++) {
		int k = 0;
		if (s[i] == 'I') {
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				k++;
				if (k == n) {
					k--;
					ans++;
				}
				i += 2;
			}
		}
	}
	cout << ans;
}

/*
	백준 5525번 IOIOI
*/
