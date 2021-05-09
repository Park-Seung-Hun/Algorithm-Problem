#include <iostream>
#include <vector>
using namespace std;

int n, k;

int factorial(int num) {
	int ans = 1;

	for (int i = 1; i <= num; i++) {
		ans *= i;
	}
	return ans;
}
int main() {
	cin >> n >> k;

	cout << factorial(n) / (factorial(k) * factorial(n - k));
}
