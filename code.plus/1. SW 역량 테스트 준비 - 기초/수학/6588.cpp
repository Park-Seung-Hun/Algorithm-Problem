#include <iostream>
#include <vector>
using namespace std;

int n, tot;
bool check[1000001];
vector<int> save;
int num[101];

void check_prime() {
	check[0] = check[1] = true;
	for (int i = 2; i*i <= 1000000; i++) {
		if (check[i] == false) {
			if (i != 2) save.push_back(i);

			for (int j = i + i; j <= 1000000; j += i) {
				check[j] = true;
			}
		}
	}
} // 에라토스테네스의 체

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	check_prime();
	int size = save.size();
	
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < size; i++) {
			int ref = save[i];
			if (ref > n) { 
				cout << "Goldbach's conjecture is wrong.";
				break; 
			}

			if (check[n - ref] == false && (n - ref) != 2) {
				cout << n << " = " << ref << " + " << n - ref << '\n';
				break;
			}
		}
	}

}

/*
	백준 6588번 골드바흐의 추측
*/