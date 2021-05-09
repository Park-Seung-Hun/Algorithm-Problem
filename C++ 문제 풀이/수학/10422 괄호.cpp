#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007

int t, l;
long long dp[2501];


int main() {
	dp[0] = 1;

	for (int i = 1; i <= 2500; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - 1 - j];
			dp[i] %= mod;
		}
		dp[i] %= mod;
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> l;

		if (l % 2 == 0) {
			int n = l / 2;
			cout << dp[n] << '\n';

		}
		else {
			cout << 0 << '\n';
		}
	}
}
