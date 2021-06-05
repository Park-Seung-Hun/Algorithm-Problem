#include <iostream>
using namespace std;
string dp[1031];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int cmp = n / 5;

	int ans = -1;
	for (int i = cmp; i >= 0; i--) {
		int tmp = n - 5 * i;
		if (tmp % 2 == 0) {
			ans = i + tmp / 2;
			break;
		}
	}
	cout << ans;
	return 0;
}

/*
  이건 DP가 아니라 그리디 인듯?
  DP 풀이는 뭐가 있을까?
*/
