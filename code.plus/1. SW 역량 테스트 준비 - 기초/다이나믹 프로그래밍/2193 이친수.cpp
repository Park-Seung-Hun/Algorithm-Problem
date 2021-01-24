#include <iostream>
using namespace std;

long long dp[91];
int n;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 1;

	cin >> n;
	for (int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n] << '\n';
}

/*
	백준 2193번 이친수
*/
