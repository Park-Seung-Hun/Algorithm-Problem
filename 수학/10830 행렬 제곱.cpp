#include <iostream>
#include <vector>
using namespace std;

int n;
long long b;
vector<vector<int>> a;
vector<vector<int>> ans;

/*행렬의 곱셈*/
vector<vector<int>> cal(vector<vector<int>> &a, vector<vector<int>>& b) {
	int n = a.size();
	vector<vector<int>> c(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	}
	return c;
}

int main() {
	cin >> n >> b;

	a.assign(n, vector<int>(n, 0));
	ans.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		ans[i][i] = 1;
	}

	/*이진수 응용*/
	while (b > 0) {
		if (b % 2 == 1) {
			ans =cal(ans, a);
		}
		a = cal(a, a);
		b /= 2;
	}

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
/*
	백준 10830번 행렬 제곱
*/
