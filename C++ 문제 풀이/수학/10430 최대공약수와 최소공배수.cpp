#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 1) return a;
	else return gcd(b, a % b);
}// 최대 공약수

int lcm(int a, int b) {
	int g = gcd(a, b);
	return g * (a / g) * (b / g);
}// 최소 공배수

int main() {
	int A, B;
	cin >> A >> B;

	cout << gcd(A, B) << '\n';
	cout << lcm(A, B) << '\n';
}

/*
	백준 10430번 최대공약수와 최소공배수
*/ 
