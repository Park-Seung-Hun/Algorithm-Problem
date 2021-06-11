#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
	int g = gcd(a, b);

	return g * (a / g) * (b / g);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;
	cin >> A >> B;
	cout << lcm(A, B);
	return 0;
}
