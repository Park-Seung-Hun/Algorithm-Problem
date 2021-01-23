#include <iostream>
using namespace std;
#define Ref 1000000009

long long dp[100001][4];
int n, t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	
	for (int i = 4; i <= 100000; i++) {
		if (i - 1 >= 0) {
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % Ref;
		}
		if (i - 2 >= 0) {
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % Ref;
		}
		if (i - 3 >= 0) {
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % Ref;
		}
	}

	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n;

		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % Ref << '\n';
	}
}

/*
	백준 15990번 1,2,3 더하기 5
*/
