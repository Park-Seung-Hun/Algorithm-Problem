#include <iostream>
using namespace std;

int n,tot;
bool check[1001];
int num[101];

void check_prime() {
	check[0] = check[1] = true;
	for (int i = 2; i <= 1000; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= 1000; j += i) {
				check[j] = true;
			}
		}
	}
} // �����佺�׳׽��� ü

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	
	check_prime();

	for (int i = 0; i < n; i++) {
		if (check[num[i]] == false) tot++;
	}
	cout << tot << '\n';
}

/*
	���� 1978�� �Ҽ� ã��
*/