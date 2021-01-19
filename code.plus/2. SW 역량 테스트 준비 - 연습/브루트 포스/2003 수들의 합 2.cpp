#include <iostream>
using namespace std;

int n, m, tot;
int num[10000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> num[i];

	int start = 0;
	int end = 0;
	int sum = 0;
	while (true) {
		if (sum >= m) sum -= num[start++];
		else if (end == n) break;
		else sum += num[end++];

		if (sum == m) tot++;
	}
	cout << tot;
}

/*
	백준 2003번 수들의 합 2
*/
