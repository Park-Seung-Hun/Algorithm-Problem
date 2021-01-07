#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}// 최대 공약수

int lcm(int a, int b) {
	int g = gcd(a, b);
	return g * (a / g) * (b / g);
}// 최소 공배수

int main() {
	int test_case;
	int A, B;

	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		cin >> A >> B;
		cout << lcm(A, B);
	}
}

/*
	백준 2609번 최대공약수와 최소공배수
*/
