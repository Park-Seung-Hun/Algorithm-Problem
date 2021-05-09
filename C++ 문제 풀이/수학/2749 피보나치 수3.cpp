#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
vector<ll> fibo;
long long n;


int main() {
	int k = 0;
	int tmp = 1000000;

	while (tmp > 0) {
		k++;
		tmp /= 10;
	}

	ll cycle = 15 * pow(10, k - 1);

	fibo.resize(cycle);
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i < cycle; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= 1000000;
	}
	cin >> n;

	cout << fibo[n % cycle];
}
/*
	주기의 길이 K
	N번째 피보나치 수를 M으로 나눈 나머지 = N%K 번째 피보나치 수
	M = 10^K, K > 2 이면, 주기는 항상 15*10^(K-1)이다.
*/
