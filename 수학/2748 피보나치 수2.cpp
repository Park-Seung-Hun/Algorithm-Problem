#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll fibo[91];
int n;

int main() {
	cin >> n;

	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[n];
}
