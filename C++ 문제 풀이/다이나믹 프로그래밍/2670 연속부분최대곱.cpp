/*
2670 연속부분최대곱
sol. DP를 이용해서 푼다.
1. DP배열을 초기화 (입력받은 수들로부터)
2. (i>=2) DP[i]*DP[i-1]>=DP[i] 이면 갱신해준다.
*/

#include <iostream>
#include <vector>
using namespace std;
double dp[10000];
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(3);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dp[i];
	}

	double ans = dp[0];
	for (int i = 1; i < N; i++) {
		if (dp[i] * dp[i - 1] >= dp[i]) {
			dp[i] = dp[i] * dp[i - 1];
		}

		if (ans < dp[i]) ans = dp[i];
	}

	cout << ans << '\n';
	return 0;
}
