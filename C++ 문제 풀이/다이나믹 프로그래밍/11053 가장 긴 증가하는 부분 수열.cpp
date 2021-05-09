#include <iostream>
using namespace std;

int num[1000];
int dp[1000];
int n,ans;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';
}

/*
	백준 11053번 가장 긴 증가하는 부분 수열
*/
