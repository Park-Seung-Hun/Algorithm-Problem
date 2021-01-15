#include <iostream>
using namespace std;

int t,n;
bool check[1000001];

void is_prime() {
	check[1] = true;
	check[0] = true;

	for (int i = 2; i*i <= 1000000; i++) {
		if (check[i] == false) {
			for (int j = i * i; j <= 1000000; j += i) {
				check[j] = true;
			}
		}
	}
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	is_prime();
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		cin >> n;
		
		int tot = 0;
		for (int j = 2; j <=n ; j++) {
			if (check[n - j] == false && check[j] == false) {
				tot++;
				if (j == n / 2) tot++;
			}
			
		}
		cout << tot / 2 << '\n';
	}
}
/*
	백준 17103번 골드바흐 파티션
*/
