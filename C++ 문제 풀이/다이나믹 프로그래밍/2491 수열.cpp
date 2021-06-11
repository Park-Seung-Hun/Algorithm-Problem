#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int p[100001];
int m[100001];
int num[100001];
int n,ma,pa;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];

	m[0] = 1;
	p[0] = 1;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (num[i - 1] < num[i]) { // 증가
			m[i] = 1;
			p[i] = p[i - 1] + 1;
		}
		else if (num[i - 1] > num[i]) { // 감소
			p[i] = 1;
			m[i] += m[i - 1]+1;
		}
		else { // 동일
			m[i] = m[i - 1]+1;
			p[i] = p[i - 1]+1;
		}
		ans = max(ans, max(m[i], p[i]));
	}
	if (n == 1) ans = 1;
	cout << ans << '\n';
	return 0;
}
