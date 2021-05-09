#include <iostream>
using namespace std;

int n, m;
int tot = 987654321;
int num[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> num[i];

	int start = 0;
	int end = 0;
	int sum = num[start];
	while (start<n&&end<n) {
		int len = end - start+1;

		if (sum < m && end == n - 1) break;

		if (sum < m) sum += num[++end];
		else if (sum > m) {
			if (tot > len) tot = len;

			sum -= num[start++];

			if (start > end) {
				end = start;
				sum = num[start];
			}
		}
		else if (sum == m) {
			if (tot > len) tot = len;

			sum += num[++end];
		}
	}
	if (tot != 987654321)cout << tot;
	else cout << 0;
}

/*
	백준 1806번 부분합
*/
