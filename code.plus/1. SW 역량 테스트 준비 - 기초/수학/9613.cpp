#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
} // 최대 공약수

int main() {
	int test_case,n;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		long long num[101];
		cin >> n;
		for (int j = 0; j < n; j++) cin >> num[j];
		long long sum = 0;
		
		for (int a = 0; a < n-1 ; a++) 
			for (int b = a+1; b < n; b++) 
				sum += gcd(num[a], num[b]);
			
		cout << sum << '\n';
	}
}

/*
	백준 9613번 GCD 합
*/