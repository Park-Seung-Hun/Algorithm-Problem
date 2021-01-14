#include <iostream>
using namespace std;

long long n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	long long tot = 0;
	long long check = 10;
	long long ref = 1;
	for (long long i = 1; i <= n; i++) {
		if (i / check == 1) {
			check *= 10;
			ref++;
		}
		tot += ref;
	}

	cout << tot;
}
/*
	백준 1748번 수 이어 쓰기 1
*/
