#include <iostream>
using namespace std;
#define Ref 10007

int dp[1001][10];
int n;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (j >= k) {
					dp[i][j] += dp[i - 1][k]%Ref;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) ans += dp[n][i];

	cout << ans%Ref << '\n';
}

/*
	백준 11057번 오르막 수
*/
