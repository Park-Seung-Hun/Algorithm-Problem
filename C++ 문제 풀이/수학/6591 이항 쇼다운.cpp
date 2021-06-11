#include <iostream>
using namespace std;

long long combination(long long n, long long r) {

	long long answer = 1;

	// nCr = nCn-r
	r = min(r, n - r);

	// nCr = nPr / r!
	for (int i = 1; i <= r; i++) {
		answer *= n;
		answer /= i;
		n--;
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, r;
	while (true) {
		cin >> n >> r;
		if (n == 0 && r == 0)
			break;
		cout << combination(n, r) << '\n';
	}

	return 0;
}
