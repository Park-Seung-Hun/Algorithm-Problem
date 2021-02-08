#include <iostream>
#include <vector>
using namespace std;
bool v[1000001];
long long a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;

	for (long long i = 2; i*i <= b; i++) {
		long long tmp = i * i - a % (i * i); 
		if (tmp == i * i) tmp = 0; // Min이 i의 제곱으로 나누어 떨어지면
    
		for (long long j = tmp; j <= b - a; j += i * i) v[j] = true;
	}
	long long ans = 0;
	for (long long i = 0; i <= b-a; i++) {
		if (v[i] == false) ans++;
	}

	cout << ans;

}
/*
	백준 1016번 제곱 ㄴㄴ수
*/
