#include <iostream>
using namespace std;

long long num[100];
long long dp[10001];
int n, k;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	dp[0] = 1;
	for (int i = 0; i < n; i++) cin >> num[i];
	
	for (int i = 0; i < n; i++) 
		for (int j = num[i]; j <= k; j++) dp[j] = dp[j] + dp[j - num[i]];
	cout << dp[k];
}

/*
	백준 2293번 동전 1
*/
