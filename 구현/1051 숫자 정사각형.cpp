#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> num;
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	num.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			num[i][j] = (s[j] - '0');
		}
	}
	int ref = min(n, m);
	int ans = 1;
	for (int t = 2; t <= ref; t++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + t - 1 < n && j + t - 1 < m) {
					int a = num[i][j];
					int b = num[i][j + t - 1];
					int c = num[i + t - 1][j];
					int d = num[i + t - 1][j + t - 1];
					if (a == b && b == c && c == d) ans = t;
				}
			}
		}
	}
	cout << ans*ans;
}

/*
	백준 1051번 숫자 정사각형
*/
