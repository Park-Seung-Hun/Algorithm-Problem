#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}// �ִ� �����

int lcm(int a, int b) {
	int g = gcd(a, b);
	return g * (a / g) * (b / g);
}// �ּ� �����

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
	���� 2690�� �ִ������� �ּҰ����
*/