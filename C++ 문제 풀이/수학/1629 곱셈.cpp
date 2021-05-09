#include <iostream>
using namespace std;

long long sol(long long a, long long b, long long c) {
	if (b == 0) return 1;
	else if (b == 1) return a%c;
	else if (b % 2 == 0) {
		long long tmp = sol(a, b / 2,c);
		return (tmp * tmp)%c;
	}
	else {
		return (a * sol(a, b - 1,c))%c;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b, c;
	cin >> a >> b >> c;
	cout<<sol(a, b, c);

}
/*
	백준 1629번 곱셈
*/
