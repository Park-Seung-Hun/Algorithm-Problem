#include <iostream>
using namespace std;

long long dp[1000001];
long long n, t;
long long r = 3;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	cin >> t;
	for (long long i = 0; i < t; i++) {
		cin >> n;
		
		if (n > r) {
			for (int i = r; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])% 1000000009;
		}
		r = n;
		cout << dp[n] << '\n';
	}
	
	
}

/*
	백준 15988번 1,2,3 더하기 3
*/
