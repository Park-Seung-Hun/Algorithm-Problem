#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1000001];

int one(int x) {
	if (x == 1) return 0;
	if (dp[x] > 0) return dp[x];

	dp[x] = one(x - 1) + 1;
	if (x % 2 == 0) {
		int tmp = one(x / 2) + 1;
		if (dp[x] > tmp) dp[x] = tmp;
	}
	if (x % 3 == 0) {
		int tmp = one(x / 3) + 1;
		if (dp[x] > tmp) dp[x] = tmp;
	}

	return dp[x];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cout << one(n);
}
/*
	백준 1463번 1로 만들기
*/
