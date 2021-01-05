#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 1) return a;
	else return gcd(b, a % b);
}// �ִ� �����

int lcm(int a, int b) {
	int g = gcd(a, b);
	return g * (a / g) * (b / g);
}// �ּ� �����

int main() {
	int A, B;
	cin >> A >> B;

	cout << gcd(A, B) << '\n';
	cout << lcm(A, B) << '\n';
}

/*
	���� 2690�� �ִ������� �ּҰ����
*/ 